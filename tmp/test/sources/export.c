/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:05:40 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/02 22:51:06 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_export(t_shell *shell, char **cmd)
{
	int	i;

	i = 0;
	if (!cmd[1])
	{
		while (shell->envp[i])
		{
			if (shell->curr_pipe[1] != -1)
			{
				write(shell->curr_pipe[1], shell->envp[i], \
				ft_strlen(shell->envp[i]));
				write(shell->curr_pipe[1], "\n", 1);
			}
			else
				ft_printf("%s\n", shell->envp[i]);
			i++;
		}
	}
	else
	{
		while (shell->envp[i])
			i++;
		shell->envp[i] = ft_strdup(cmd[1]);
	}
}
