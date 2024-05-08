/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:11:54 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/07 19:33:09 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_shell *shell, char **cmd)
{
	int		pid;
	char	*cmd_path;
	
	pid = fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (builtin_check(shell, cmd) == 0)
		{
			dup2_exe(shell);
			child_free(shell);
			cmd_path = get_cmd(shell, cmd);
			if (execve(cmd_path, cmd, shell->envp) < 0)
				exit(1);
		}
	}
	else
	{
		waitpid(pid, &shell->status, 0);
		if (shell->prev_fd != -1)
			close(shell->prev_fd);
		close(shell->curr_pipe[1]);
		shell->prev_fd = shell->curr_pipe[0];
	}
}

void	dup2_exe(t_shell *shell)
{
	if (shell->infile != -1)
	{
		if (dup2(shell->infile, STDIN_FILENO) < 0)
			exit(1);
	}
	else
	{
		if (dup2(shell->prev_fd, STDIN_FILENO) < 0)
			exit(1);
		close(shell->prev_fd);
	}
	if (shell->outfile != -1)
	{
		if (dup2(shell->outfile, STDOUT_FILENO) < 0)
			exit(1);
	}
	else
	{
		if (dup2(shell->curr_pipe[1], STDOUT_FILENO) < 0)
			exit(1);
		close(shell->curr_pipe[1]);
	}
	close(shell->curr_pipe[0]);
}
