/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 17:17:35 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/05 17:17:42 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_cmd(t_shell *shell, char **cmd)
{
	char	*tmp;
	char	*path;
	int		i;

	i = 0;
	while (shell->paths[i])
	{
		tmp = ft_strjoin(shell->paths[i], "/");
		path = ft_strjoin(tmp, cmd[0]);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	if (access(cmd[0], F_OK) == 0)
		return (cmd[0]);
	return (NULL);
}