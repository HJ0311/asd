/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:56:01 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/06 18:49:10 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	n1;
t_token	n2;
t_token	n3;
t_token	n4;
t_token	n5;
t_token	n6;
t_token	n7;
t_token	n8;
t_token	n9;
t_token	n10;

void	check(void)
{
	system("leaks minishell");
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	(void)argc;
	(void)argv;
	display_main();
	init_info(envp, &shell);
	display_prompt(&shell);
	
	get_input(&shell);
	
	if (pipe_check(&shell, shell.root) == 0)
		multi_cmd_run(&shell, shell.root);

	free_shell(&shell);
	// atexit(check);
	return (0);
}

void	get_input(t_shell *shell)
{

	// test 1
	
	// char	**cmd;
	
	// cmd = (char **)malloc(sizeof(char *) * 3);
	// cmd[0] = "sleep";
	// cmd[1] = "5";
	// cmd[2] = NULL;

	// n1 = (t_token){COMMAND, cmd, NULL, NULL, NULL};
	// n2 = (t_token){PHRASE, NULL, NULL, &n1, NULL};
	// shell->root = &n2;

	


	// test 2

	// char	**cmd;
	// t_red	*red;

	// cmd = (char **)malloc(sizeof(char *) * 3);
	// cmd[0] = "cat";
	// cmd[1] = "-e";
	// cmd[2] = NULL;

	// red = (t_red *)malloc(sizeof(t_red));
	// red->filename = "outfile.txt";
	// red->next = NULL;
	// red->type = OUT;
	// n1 = (t_token){COMMAND, cmd, NULL, NULL, NULL};
	// n2 = (t_token){REDIRECTION, NULL, red, NULL, NULL};
	// n3 = (t_token){PHRASE, NULL, NULL, &n2, &n1};
	// shell->root = &n3;
	


	
	// test 3

	// char	**cmd;
	// t_red	*red;
	// t_red	*tmp_red;
	
	// cmd = (char **)malloc(sizeof(char *) * 3);
	// cmd[0] = "cat";
	// cmd[1] = "-e";
	// cmd[2] = NULL;

	// tmp_red = (t_red *)malloc(sizeof(t_red));
	// tmp_red->filename = NULL;
	// tmp_red->next = NULL;
	// tmp_red->type = DOUBLE_IN;
	
	// red = (t_red *)malloc(sizeof(t_red));
	// red->filename = "outfile.txt";
	// red->next = tmp_red;
	// red->type = OUT;
	
	// shell->limiter = "eof";
	// n1 = (t_token){COMMAND, cmd, NULL, NULL, NULL};
	// n2 = (t_token){REDIRECTION, NULL, red, NULL, NULL};
	// n3 = (t_token){PHRASE, NULL, NULL, &n2, &n1};
	// shell->root = &n3;



	// test 4

	// char	**cmd;
	// t_red	*red;
	
	// cmd = (char **)malloc(sizeof(char *) * 3);
	// cmd[0] = "echo";
	// cmd[1] = "Hello";
	// cmd[2] = NULL;
	
	// red = (t_red *)malloc(sizeof(t_red));
	// red->filename = "outfile.txt";
	// red->next = NULL;
	// red->type = OUT;
	
	// n1 = (t_token){COMMAND, cmd, NULL, NULL, NULL};
	// n2 = (t_token){REDIRECTION, NULL, red, NULL, NULL};
	// n3 = (t_token){PHRASE, NULL, NULL, &n2, &n1};
	// shell->root = &n3;





	// test 5

	char	**cmd1;
	char	**cmd2;
	char	**cmd3;

	cmd1 = (char **)malloc(sizeof(char *) * 3);
	cmd2 = (char **)malloc(sizeof(char *) * 3);
	cmd3 = (char **)malloc(sizeof(char *) * 3);

	cmd1[0] = "cat";
	cmd1[1] = "-e";
	cmd1[2] = NULL;
	
	cmd2[0] = "ls";
	cmd2[1] = "-e";
	cmd2[2] = NULL;
	
	cmd3[0] = "wc";
	cmd3[1] = "-l";
	cmd3[2] = NULL;

	n1 = (t_token){COMMAND, cmd1, NULL, NULL, NULL};
	n2 = (t_token){PHRASE, NULL, NULL, &n1, NULL};
	n3 = (t_token){COMMAND, cmd2, NULL, NULL, NULL};
	n4 = (t_token){PHRASE, NULL, NULL, &n3, NULL};
	n5 = (t_token){COMMAND, cmd3, NULL, NULL, NULL};
	n6 = (t_token){PHRASE, NULL, NULL, &n5, NULL};
	n7 = (t_token){PIPE, NULL, NULL, &n6, NULL};
	n8 = (t_token){PIPE, NULL, NULL, &n4, &n7};
	n9 = (t_token){PIPE, NULL, NULL, &n2, &n8};
	shell->cmd_num = 3;
	shell->root = &n9;
}