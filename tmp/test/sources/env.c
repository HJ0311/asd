/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:05:21 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/02 22:40:15 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_env(t_shell *shell)
{
	int	i;

	i = 0;
	if (shell->curr_pipe[1] != -1)
	{
		while (shell->envp[i])
		{
			write(shell->curr_pipe[1], shell->envp[i], \
			ft_strlen(shell->envp[i]));
			write(shell->curr_pipe[1], "\n", 1);
			i++;
		}
	}
	while (shell->envp[i])
	{
		ft_printf("%s\n", shell->envp[i]);
		i++;
	}
}
