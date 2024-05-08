/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 16:28:45 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/06 17:12:18 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pipe_check(t_shell *shell, t_token *tree)
{
	if (tree->type == PIPE)
		return (0);
	else
	{
		single_cmd_run(shell, tree);
		return (1);
	}
}