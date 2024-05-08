/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:05:08 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/05 18:34:36 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_echo(t_shell *shell, char **cmd)
{
	if (ft_strncmp(cmd[1], "$?", 2) == 0)
		cmd[1] = ft_itoa(shell->status);
	if (shell->n_flag == 0)
		cmd[1] = ft_strjoin(cmd[1], "\n");
	if (shell->curr_pipe[1] != -1)
		write(shell->curr_pipe[1], cmd[1], ft_strlen(cmd[1]));
	else
		ft_printf("%s", cmd[1]);
}