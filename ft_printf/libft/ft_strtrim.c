/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:10:36 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/01 16:17:15 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocate for copy str of s1 removed from the begin' and the end of the str
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	if (s1[start] == '\0')
		result = ft_calloc(sizeof(char), 1);
	else
	{
		while (end > 0 && ft_strchr(set, s1[end - 1]))
			end--;
		if (start > end)
			result = ft_calloc(sizeof(char), 1);
		else
			result = ft_calloc(sizeof(char), end - start + 1);
		if (result == NULL)
			return (NULL);
		ft_strlcpy(result, s1 + start, end - start + 1);
	}
	return (result);
}
