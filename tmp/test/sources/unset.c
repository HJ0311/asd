/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:06:08 by hyehan            #+#    #+#             */
/*   Updated: 2024/04/30 05:23:30 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_unset(t_shell *shell, char **cmd)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(cmd[1]);
	while (shell->envp[i] && ft_strncmp(shell->envp[i], cmd[1], len != 0))
		i++;
	while (shell->envp[i])
	{
		shell->envp[i] = shell->envp[i + 1];
		i++;
	}
}