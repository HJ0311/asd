/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:05:48 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/06 17:32:14 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->envp[i])
	{
		free(shell->envp[i]);
		i++;
	}
	free(shell->envp);
	i = 0;
	while(shell->paths[i])
	{
		free(shell->paths[i]);
		i++;
	}
	free(shell->paths);
	free(shell->home);
}
