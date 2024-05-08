/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 02:12:30 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/08 15:53:44 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_info(char **envp, t_shell *shell)
{
	init_envp(envp, shell);
	find_path(shell);
	shell->prev_fd = -1;
	shell->curr_pipe[0] = -1;
	shell->curr_pipe[1] = -1;
	shell->status = 0;
	shell->n_flag = 0;
	shell->origin_in = dup(0);
	shell->origin_out = dup(1);
	shell->infile = -1;
	shell->outfile = -1;
	shell->idx = 0;
}

void	init_envp(char **envp, t_shell *shell)
{
	int		i;
	size_t	cnt;
	
	cnt = 0;
	i = 0;
	while (envp[cnt])
		cnt++;
	shell->envp = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!shell->envp)
		exit(1);
	while (envp[i])
	{
		shell->envp[i] = ft_strdup(envp[i]);
		i++;
	}
	shell->envp[i] = NULL;
}

void	find_path(t_shell *shell)
{
	int	i;

	i = 0;
	while (ft_strncmp(shell->envp[i], "PATH=", 5) != 0)
		i++;
	if (!shell->envp[i])
		exit(1);
	shell->paths = ft_split(shell->envp[i] + 5, ':');
}