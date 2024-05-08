/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_cmd_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:30:15 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/06 19:56:35 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	single_cmd_run(t_shell *shell, t_token *tree)
{
	if (tree->left && tree->left->type == REDIRECTION)
	{
		single_redirection(shell, tree->left->red);
		child_process(shell, tree->right->cmd);
	}
	else if (tree->left && tree->left->type == COMMAND)
		child_process(shell, tree->left->cmd);
}

void	single_redirection(t_shell *shell, t_red *cur)
{
	while (cur)
	{
		if (cur->type == IN)
		{
			shell->prev_fd = open(cur->filename, O_RDONLY);
			if (shell->prev_fd < 0)
				exit(1);
		}
		else if (cur->type == DOUBLE_IN)
			shell->prev_fd = here_doc(shell->limiter);
		else if (cur->type == OUT)
		{
			shell->curr_pipe[1] = open(cur->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (shell->curr_pipe[1] < 0)
				exit(1);
		}
		else if (cur->type == DOUBLE_OUT)
		{
			shell->curr_pipe[1] = open(cur->filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
			if (shell->curr_pipe < 0)
				exit(1);
		}
		cur = cur->next;
	}
}
