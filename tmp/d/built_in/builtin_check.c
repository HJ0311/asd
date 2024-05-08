/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:01:28 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/05 17:18:17 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_check(t_shell *shell, char **cmd)
{
	if (ft_strncmp(cmd[0], "echo", 4) == 0)
		exec_echo(shell, cmd);
	else if (ft_strncmp(cmd[0], "cd", 2) == 0)
		exec_cd(shell, cmd);
	else if (ft_strncmp(cmd[0], "pwd", 3) == 0)
		exec_pwd(shell);
	else if (ft_strncmp(cmd[0], "export", 5) == 0)
		exec_export(shell, cmd);
	else if (ft_strncmp(cmd[0], "unset", 5) == 0)
		exec_unset(shell, cmd);
	else if (ft_strncmp(cmd[0], "env", 3) == 0)
		exec_env(shell);
	else if (ft_strncmp(cmd[0], "exit", 4) == 0)
		exec_exit();
	else
		return (0);
	return (1);
}
