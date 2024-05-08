/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 04:04:18 by hyehan            #+#    #+#             */
/*   Updated: 2024/04/30 09:26:02 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cd(t_shell *shell, char **cmd)
{
	if (ft_strncmp(cmd[1], "~", 1) == 0)
	{
		if (chdir(shell->home) < 0)
			exit(1);
	}
	else if (ft_strncmp(cmd[1], ".", 2) == 0)
	{
		if (chdir(".") < 0)
			exit(1);
	}
	else if (ft_strncmp(cmd[1], "..", 2) == 0)
	{
		if (chdir("..") < 0)
			exit(1);
	}
	else
	{
		if (chdir(cmd[1]) < 0)
			exit(1);
	}
}
