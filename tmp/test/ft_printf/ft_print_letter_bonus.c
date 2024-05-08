/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_letter_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:57:04 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/30 12:33:19 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c(t_info *info, int c)
{
	int	print_len;

	print_len = 0;
	if (info->f_left == OFF)
	{
		print_len += ft_print_write(info, ' ', info->width - 1);
		info->width = 0;
	}
	print_len += ft_print_write(info, c, 1);
	print_len += ft_print_write(info, ' ', info->width - 1);
	return (print_len);
}

int	ft_print_s(t_info *info, char *str)
{
	int	print_len;
	int	strlen;
	int	gap;

	print_len = 0;
	if (str == NULL)
		str = NULL_STR;
	strlen = ft_strlen(str);
	if (0 < info->prec && info->prec < strlen)
		strlen = info->prec;
	if (info->f_dot_only == ON || info->prec == 0)
		strlen = 0;
	gap = info->width - strlen;
	if (info->f_left == OFF)
	{
		print_len += ft_print_write(info, ' ', gap);
		gap = 0;
	}
	while (strlen-- > 0)
	{
		print_len += ft_print_write(info, *str, 1);
		str++;
	}
	print_len += ft_print_write(info, ' ', gap);
	return (print_len);
}

int	ft_print_pct(t_info *info)
{
	int	print_len;

	print_len = 0;
	if (info->f_left == OFF)
	{
		if (info->f_zero == ON)
			print_len += ft_print_write(info, '0', info->width - 1);
		else
			print_len += ft_print_write(info, ' ', info->width - 1);
		info->width = 0;
	}
	print_len += ft_print_write(info, '%', 1);
	print_len += ft_print_write(info, ' ', info->width - 1);
	return (print_len);
}
