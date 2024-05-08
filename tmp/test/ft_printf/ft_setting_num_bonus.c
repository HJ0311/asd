/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setting_num_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:44:40 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/30 12:33:27 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(t_info *info, void *ptr)
{
	char	nbr[21];
	int		numlen;

	ft_onoff(info);
	info->width -= 2;
	ft_itoa_base((size_t)ptr, LHEX, nbr);
	numlen = ft_strlen(nbr);
	return (ft_print_num(info, nbr, numlen, 'p'));
}

int	ft_print_di(t_info *info, long long num)
{
	char	nbr[21];
	int		numlen;

	if ((info->f_blank == ON || info->f_sign == ON) && num >= 0)
		info->width -= 1;
	if (num < 0)
	{
		info->num_sign = -1;
		num = -num;
		info->width -= 1;
	}
	else if (num == 0)
		info->num_sign = 0;
	ft_onoff(info);
	ft_itoa_base(num, DEC, nbr);
	numlen = ft_strlen(nbr);
	return (ft_print_num(info, nbr, numlen, 0));
}

int	ft_print_u(t_info *info, unsigned int num)
{
	char	nbr[21];
	int		numlen;

	ft_onoff(info);
	if (num == 0)
		info->num_sign = 0;
	ft_itoa_base(num, DEC, nbr);
	numlen = ft_strlen(nbr);
	return (ft_print_num(info, nbr, numlen, 0));
}

int	ft_print_x(t_info *info, unsigned int num, char s)
{
	char	nbr[21];
	int		numlen;

	ft_onoff(info);
	if (num == 0)
		info->num_sign = 0;
	if (s == 'x')
		ft_itoa_base(num, LHEX, nbr);
	else if (s == 'X')
		ft_itoa_base(num, UHEX, nbr);
	if (info->f_hash == ON && num != 0)
		info->width -= 2;
	numlen = ft_strlen(nbr);
	return (ft_print_num(info, nbr, numlen, s));
}
