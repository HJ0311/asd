/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:16:22 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/08 15:52:54 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <readline/readline.h>
#include "../ft_printf/ft_printf.h"

typedef	enum e_rdr_type
{
	IN,
	DOUBLE_IN,
	OUT,
	DOUBLE_OUT
}	t_rdr_type;

typedef enum e_type
{
	PIPE,
	PHRASE,
	COMMAND,
	REDIRECTION
}	t_type;

typedef struct	s_red
{
	char			*filename;
	t_rdr_type		type;
	struct s_red	*next;
}	t_red;

typedef union	u_content
{
	char	**cmd;
	t_red	*red;
}	t_content;

typedef struct	s_token
{
	t_type			type;
	t_content		*content;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct s_shell
{
	t_token	*root;
	char	**envp;
	char	**paths;
	char	*pwd;
	char	*home;
	int		prev_fd;
	int		curr_pipe[2];
	char	*limiter;
	int		status;
	int		n_flag;
	int		origin_in;
	int		origin_out;
	int		infile;
	int		outfile;
	int		cmd_num;
	int		idx;
}	t_shell;


/* main */
void	get_input(t_shell *shell);
void	display_main(void);
void	display_prompt(t_shell *shell);
void	free_shell(t_shell *shell);
int		here_doc(char *limiter);
void	init_info(char **envp, t_shell *shell);
void	init_envp(char **envp, t_shell *shell);
void	find_path(t_shell *shell);
void	pipe_run(t_shell *shell, t_token *tree);
void	set_redirection(t_shell *shell, t_red *red);
void	create_pipe(t_shell *shell);
int		get_infile(t_shell *shell, t_rdr_type type, char *filename);
int		get_outfile(t_rdr_type type, char *filename);
void	child_process(t_shell *shell, char **cmd);
void	dup2_exe(t_shell *shell);
char	*get_cmd(t_shell *shell, char **cmd);
void	exec_cd(t_shell *shell, char **cmd);
void	exec_echo(t_shell *shell, char **cmd);
void	exec_env(t_shell *shell);
void	exec_exit(void);
void	exec_export(t_shell *shell, char **cmd);
void	exec_pwd(t_shell *shell);
void	exec_unset(t_shell *shell, char **cmd);
int		builtin_check(t_shell *shell, char **cmd);
void	close_pipe(t_shell *shell);

#endif