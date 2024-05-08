/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:11:30 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/08 16:29:30 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	child_process(t_shell *shell, char **cmd)
{
	int		pid;
	char	*cmd_path;
	
	pid	= fork();
	if (pid < 0)
		exit(1);
	if (pid == 0)
	{
		if (builtin_check(shell, cmd) == 0)
		{
			dup2_exe(shell);
			close_pipe(shell);
			cmd_path = get_cmd(shell, cmd);
			if (execve(cmd_path, cmd, shell->envp) < 0)
				exit(1);
		}
	}
	else
		waitpid(pid, &shell->status, 0);
}

void	dup2_exe(t_shell *shell)
{
	if (shell->prev_fd != -1)
	{
		if (dup2(shell->prev_fd, STDIN_FILENO) < 0)
			exit(1);
		close(shell->prev_fd);
	}
	if (dup2(shell->curr_pipe[1], STDOUT_FILENO) < 0)
		exit(1);
}

void	close_pipe(t_shell *shell)
{
	close(shell->prev_fd);
	close(shell->curr_pipe[0]);
	close(shell->curr_pipe[1]);
}