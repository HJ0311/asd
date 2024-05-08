/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:41:30 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/01 16:29:39 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* allocate for string obtained by splitting s using c */
#include "libft.h"

int	word_check(char const *s, char c);
int	word_cpy(char const *s, char c, char **result, int word_cnt);
int	word_allocating(char **result, char *start, char *s);

char	**ft_split(char const *s, char c)
{
	int		word_cnt;
	char	**result;
	int		i;

	word_cnt = word_check(s, c);
	result = ft_calloc(word_cnt + 1, sizeof(char *));
	if (result == NULL)
		return (NULL);
	if (word_cpy(s, c, result, word_cnt) == 0)
	{
		i = 0;
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
		return (NULL);
	}
	return (result);
}

int	word_check(char const *s, char c)
{
	int	flag;
	int	word_cnt;

	flag = 0;
	word_cnt = 0;
	while (*s)
	{
		if (*s == c && flag == 1)
		{
			word_cnt++;
			flag = 0;
		}
		else if (*s != c)
			flag = 1;
		s++;
	}
	if (*s == '\0' && flag == 1)
		word_cnt++;
	return (word_cnt);
}
// flag --> compare current char and previous char
// if (*s == c && flag == 1) --> meet charset and previous char is word
// else if (*s != c) --> meet not charset

int	word_cpy(char const *s, char c, char **result, int word_cnt)
{
	char	*start;
	int		flag;

	flag = 0;
	while (word_cnt > 0)
	{
		if (*s != c && flag == 0)
		{
			start = (char *)s;
			flag = 1;
		}
		else if ((*s == c && flag == 1) || *s == '\0')
		{
			if (word_allocating(result, start, (char *)s) == 0)
				return (0);
			result++;
			flag = 0;
			word_cnt--;
		}
		s++;
	}
	return (1);
}
// flag --> current char is word? flag 1 : flag 0
// if (*s != && flag == 0) --> meet current char is not word
// else if ((*s == c && flag == 1) || * s == '\0)
// --> meet null or charset and previous char is word

int	word_allocating(char **result, char *start, char *s)
{
	int	word_len;
	int	i;

	i = 0;
	word_len = s - start;
	*result = ft_calloc(sizeof(char), word_len + 1);
	if (*result == NULL)
		return (0);
	while (word_len > 0)
	{
		*(*result + i) = *start;
		start++;
		i++;
		word_len--;
	}
	*(*result + i) = '\0';
	return (1);
}
