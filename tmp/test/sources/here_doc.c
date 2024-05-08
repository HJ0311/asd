/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 05:36:17 by hyehan            #+#    #+#             */
/*   Updated: 2024/05/05 18:08:31 by hyehan           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	here_doc(char *limiter)
{
	int		fd;
	char	*input;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		exit(1);
	while (1)
	{
		input = readline("> ");
		if (!input)
			break;
		if (ft_strncmp(input, limiter, ft_strlen(input)) == 0)
			break;
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free(input);
	}
	free(input);
	close(fd);
	return (open(".tmp", O_RDONLY));
}