/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_cmd_run.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:02:28 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/07 19:31:12 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	multi_cmd_run(t_shell *shell, t_token *tree)
{
	if (tree && tree->type == PHRASE)
	{
		if (tree->left && tree->left->type == REDIRECTION)
		{
			get_file(shell, tree->left->red);
			if (pipe(shell->curr_pipe) < 0)
				exit(1);
			child_process(shell, tree->left->cmd);
		}
		else if (tree->right && tree->right->type == COMMAND)
		{
			if (pipe(shell->curr_pipe) < 0)
				exit(1);
			child_process(shell, tree->right->cmd);
		}
	}
	else if (tree && tree->type == PIPE)
		multi_cmd_run(shell, tree->left);
	if (tree && tree->right)
		multi_cmd_run(shell, tree->right);
}

void	get_file(t_shell *shell, t_red *red)
{
	while (red)
	{
		if (red->type == IN || red->type == DOUBLE_IN)
		{
			if (shell->infile != -1)
				close(shell->infile);
			shell->infile = get_infile(shell, red->type, red->filename);
			if (shell->infile < 0)
				exit(1);
		}
		else if (red->type == OUT || red->type == DOUBLE_OUT)
		{
			if (shell->outfile != -1)
				close(shell->outfile);
			shell->outfile = get_outfile(red->type, red->filename);
			if (shell->outfile < 0)
				exit(1);
		}
		red = red->next;
	}
}

int	get_infile(t_shell *shell, int type, char *filename)
{
	int	fd;
	
	fd = -1;
	if (type == IN)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			exit(1);
	}
	else if (type == DOUBLE_IN)
	{
		fd = here_doc(shell->limiter);
		if (fd < 0)
			exit(1);
	}
	return (fd);
}

int	get_outfile(int type, char *filename)
{
	int	fd;

	fd = -1;
	if (type == OUT)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			exit(1);
	}
	else if (type == DOUBLE_OUT)
	{
		fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd < 0)
			exit(1);
	}
	return (fd);
}