/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:56:49 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/05 16:31:52 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_main(void)
{
	ft_printf("* ******************************************************* *\n");
	ft_printf("*                _         _       _            _  _      *\n");
	ft_printf("*               (_)       (_)     | |          | || |     *\n");
	ft_printf("*     _ __ ___   _  _ __   _  ___ | |__    ___ | || |     *\n");
	ft_printf("*    | '_ ` _ \\ | || '_ \\ | |/ __|| '_ \\  / _ \\| || |     *\n");
	ft_printf("*    | | | | | || || | | || |\\__ \\| | | ||  __/| || |     *\n");
	ft_printf("*    |_| |_| |_||_||_| |_||_||___/|_| |_| \\___||_||_|     *\n");
	ft_printf("*                                                         *\n");
	ft_printf("* ******************************************************* *\n");
	ft_printf("\n");
}

void	display_prompt(t_shell *shell)
{
	char	buf[2048 + 1];
	int		i;
	char	*home_pwd;

	i = 0;
	shell->pwd = getcwd(buf, 2048);
	if (!shell->pwd)
		exit(1);
	while (ft_strncmp(shell->envp[i], "HOME=", 5) != 0)
		i++;
	if (!shell->envp[i])
		exit(1);
	shell->home = ft_strdup(shell->envp[i] + 5);
	i = 0;
	while ((shell->pwd[i] && shell->home[i]) && shell->pwd[i] == shell->home[i])
		i++;
	home_pwd = ft_strjoin("~", &shell->pwd[i]);
	ft_printf("%s\n", home_pwd);
	free(home_pwd);
}