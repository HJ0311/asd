/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:14:36 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/27 13:35:26 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_itoa_base(size_t num, char *base, char *nbr)
{
	int	nbrlen;
	int	lbase;

	lbase = ft_strlen(base);
	nbrlen = cnt_size(num, lbase);
	nbr[nbrlen] = '\0';
	if (num == 0)
		nbr[0] = '0';
	else
	{
		while (--nbrlen >= 0)
		{
			nbr[nbrlen] = base[num % lbase];
			num /= lbase;
		}
	}
}

int	cnt_size(size_t num, int lbase)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	while (num > 0)
	{
		num /= lbase;
		len++;
	}
	return (len);
}
