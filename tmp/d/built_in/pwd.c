/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:05:56 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/02 22:52:39 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_pwd(t_shell *shell)
{
	if (shell->curr_pipe[1] != -1)
	{
		write(shell->curr_pipe[1], shell->pwd, ft_strlen(shell->pwd));
		write(shell->curr_pipe[1], "\n", 1);
	}
	else
		ft_printf("%s\n", shell->pwd);
}