/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:27:18 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/08 17:50:22 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipe_run(t_shell *shell, t_token *tree)
{
	if (tree == NULL)
		return ;
	if (tree->type == PIPE)
		pipe_run(shell, tree->left);
	else if (tree->type == PHRASE)
	{
		if (tree->left->type == COMMAND)
		{
			create_pipe(shell);
			child_process(shell, tree->left->content->cmd);
		}
		shell->idx++;
	}
	if (tree->right)
		pipe_run(shell, tree->right);
}

void	create_pipe(t_shell *shell)
{
	if (shell->idx == 0)
	{
		if (shell->infile != -1)
			shell->prev_fd = shell->infile;
		if (pipe(shell->curr_pipe) < 0)
			exit(1);
	}
	else if (shell->idx < shell->cmd_num)
	{
		shell->prev_fd = shell->curr_pipe[0];
		close(shell->curr_pipe[1]);
		if (pipe(shell->curr_pipe) < 0)
			exit(1);
		if (shell->outfile != -1)
		{
			close(shell->curr_pipe[1]);
			shell->curr_pipe[1] = shell->outfile;
		}
	}
}

void	set_redirection(t_shell *shell, t_red *red)
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

int	get_infile(t_shell *shell, t_rdr_type type, char *filename)
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

int	get_outfile(t_rdr_type type, char *filename)
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
