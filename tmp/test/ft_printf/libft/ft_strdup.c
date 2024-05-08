/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:01:25 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/01 16:15:34 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates memory for copy of the string s1
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ary;
	size_t		len;
	int			i;

	i = 0;
	len = ft_strlen(s1);
	ary = (char *)malloc(sizeof(char) * (len + 1));
	if (ary == NULL)
		return (NULL);
	while (s1[i])
	{
		ary[i] = s1[i];
		i++;
	}
	ary[i] = '\0';
	return (ary);
}
