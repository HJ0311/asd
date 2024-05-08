/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:04:48 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/31 13:27:51 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// copies len bytes from string src to string dst
#include "libft.h"

void	copy_str_back(unsigned char *dst, unsigned char *src, size_t idx);

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	if (d > s)
		copy_str_back(d, s, len);
	else
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (dst);
}

void	copy_str_back(unsigned char *dst, unsigned char *src, size_t idx)
{
	while (idx > 0)
	{
		idx--;
		dst[idx] = src[idx];
	}
}
