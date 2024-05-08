/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:08:18 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/31 00:59:51 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* allocates memory from start to len bytes and create the substring */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (s_len < start)
	{
		start = 0;
		len = 0;
	}
	if (s_len < len + start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i + start < s_len && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
