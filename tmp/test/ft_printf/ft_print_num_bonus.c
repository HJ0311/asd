/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:27:07 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/30 12:33:21 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_num(t_info *info, char *nbr, int numlen, char specifier)
{
	int	print_len;
	int	gap;

	print_len = 0;
	if ((info->f_dot_only == ON || info->prec == 0) && info->num_sign == 0)
		numlen = 0;
	gap = info->width - ft_max(info->prec, numlen);
	if ((info->f_left == OFF && gap > 0)
		&& ((info->f_zero == OFF && info->prec < 0) || info->f_dot_only == ON))
	{
		print_len += ft_print_write(info, ' ', gap);
		gap = 0;
	}
	if (info->f_left == OFF && gap > 0 && info->prec >= 0)
		print_len += ft_print_write(info, ' ', gap);
	print_len += ft_print_sign(info, specifier);
	if (info->width > numlen && info->f_zero == ON)
		print_len += ft_print_write(info, '0', gap);
	if (info->prec > 0)
		print_len += ft_print_write(info, '0', info->prec - numlen);
	while (*nbr != 0 && numlen != 0)
		print_len += ft_print_write(info, *(nbr++), 1);
	if (info->f_left == ON && gap > 0)
		print_len += ft_print_write(info, ' ', gap);
	return (print_len);
}

int	ft_print_sign(t_info *info, char s)
{
	int	print_len;

	print_len = 0;
	if (s == 'x' || s == 'X' || s == 'p')
		print_len += ft_print_prefix(info, s);
	else
	{
		if (info->num_sign == 1 || info->num_sign == 0)
		{
			if (info->f_blank)
				print_len += ft_print_write(info, ' ', 1);
			else if (info->f_sign)
				print_len += ft_print_write(info, '+', 1);
		}
		else
		print_len += ft_print_write(info, '-', 1);
	}
	return (print_len);
}

int	ft_print_prefix(t_info *info, char s)
{
	int	print_len;

	print_len = 0;
	if (s == 'p')
	{
		print_len += ft_print_write(info, '0', 1);
		print_len += ft_print_write(info, 'x', 1);
	}
	if ((s == 'x' || s == 'X') && info->f_hash == ON && info->num_sign != 0)
	{
		print_len += ft_print_write(info, '0', 1);
		if (s == 'x' || s == 'p')
			print_len += ft_print_write(info, 'x', 1);
		else if (s == 'X')
			print_len += ft_print_write(info, 'X', 1);
	}
	return (print_len);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
