/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 08:35:11 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/28 19:25:04 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// outputs the char 'c'
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}