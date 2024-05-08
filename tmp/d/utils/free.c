/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:48 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/06 19:56:16 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		free(shell->envp[i]);
		i++;
	}
	free(shell->envp);
	i = 0;
	while(shell->paths[i])
	{
		free(shell->paths[i]);
		i++;
	}
	free(shell->paths);
	free(shell->home);
}

void	child_free(t_shell *shell)
{
	if (shell->prev_fd != -1)
	{
		close(shell->prev_fd);
		shell->prev_fd = -1;
	}
	if (shell->curr_pipe[0] != -1)
	{
		close(shell->curr_pipe[0]);
		shell->curr_pipe[0] = -1;
	}
	if (shell->curr_pipe[1] != -1)
	{
		close(shell->curr_pipe[1]);
		shell->curr_pipe[1] = -1;
	}
	unlink(".tmp");
}

void	parent_free(t_shell *shell)
{
	if (shell->prev_fd != -1)
	{
		close(shell->prev_fd);
		shell->prev_fd = -1;
	}
	if (shell->curr_pipe[1] != -1)
	{
		close(shell->curr_pipe[1]);
		shell->curr_pipe[1] = -1;
	}
	unlink(".tmp");
}