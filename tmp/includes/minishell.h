/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 00:16:22 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/08 18:05:12 by hyehan           ###   ########seoul.kr  */
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

#define	IN 0
#define	DOUBLE_IN 1
#define	OUT 2
#define	DOUBLE_OUT 3

typedef enum
{
	PIPE,
	PHRASE,
	COMMAND,
	REDIRECTION,
	WORD
}	e_type;

typedef struct	s_red
{
	char			*filename;
	int				type;
	struct s_red	*next;
}	t_red;

typedef struct	s_token
{
	e_type			type;
	char			**cmd;
	t_red			*red;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

typedef struct	s_pipe
{
	int	prev_fd;
	int	curr_pipe[2];
	int	origin_in;
	int	origin_out;
	int	infile;
	int	outfile;
}	t_pipe;

typedef struct	s_info
{
	char	**envp;
	char	*
}
typedef struct s_shell
{
	t_token	*root;
	char	**envp;
	char	**paths;
	char	*pwd;
	char	*home;
	t_pipe	pipe;
	char	*limiter;
	int		status;
	int		n_flag;
	int		cmd_num;
}	t_shell;

typedef struct s_lst
{
	int				fd;
	char			*remain;
}	t_lst;

/* main */
void	display_main(void);
void	display_prompt(t_shell *shell);
void	get_input(t_shell *shell);

/* built in */
int		builtin_check(t_shell *shell, char **cmd);
void	exec_cd(t_shell *shell, char **cmd);
void	dup2_exe(t_shell *shell);
void	exec_echo(t_shell *shell, char **cmd);
void	exec_env(t_shell *shell);
void	exec_exit(void);
void	exec_export(t_shell *shell, char **cmd);
char	*get_cmd(t_shell *shell, char **cmd);
int		pipe_check(t_shell *shell, t_token *tree);
void	exec_pwd(t_shell *shell);
void	exec_unset(t_shell *shell, char **cmd);

/* exec */
int		here_doc(char *limiter);
void	single_cmd_run(t_shell *shell, t_token *tree);
void	single_redirection(t_shell *shell, t_red *cur);
void	child_process(t_shell *shell, char **cmd);
void	multi_cmd_run(t_shell *shell, t_token *tree);
void	get_file(t_shell *shell, t_red *red);
int		get_infile(t_shell *shell, int type, char *filename);
int	get_outfile(int type, char *filename);

/* utils */
void	init_info(char **envp, t_shell *shell);
void	init_envp(char **envp, t_shell *shell);
void	find_path(t_shell *shell);
void	free_shell(t_shell *shell);
void	child_free(t_shell *shell);
void	parent_free(t_shell *shell);

#endif