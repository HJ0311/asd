/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 18:47:41 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/10 11:40:37 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// converts int to char
#include "libft.h"

int		cnt_len(long n);
void	change(char *result, int i, long n);

char	*ft_itoa(int n)
{
	int		len;
	char	*result;

	len = cnt_len((long)n);
	result = ft_calloc(len + 1, sizeof(char));
	if (result == NULL)
		return (NULL);
	change(result, len, n);
	return (result);
}

int	cnt_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	change(char *result, int i, long n)
{
	result[i--] = '\0';
	if (n == 0)
		result[0] = '0';
	if (n < 0)
	{
		result[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
}
