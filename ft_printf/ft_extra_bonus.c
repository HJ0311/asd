/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:25:35 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/28 18:49:50 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	isflag(char c)
{
	if (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}

int	ft_atoi_mini(const char **format)
{
	int	result;

	result = 0;
	while (ft_isdigit(**format))
	{
		result = result * 10 + (**format - '0');
		(*format)++;
	}
	return (result);
}

void	ft_onoff(t_info *info)
{
	if (info->f_left == ON)
		info->f_zero = OFF;
	if (info->prec >= 0)
		info->f_zero = OFF;
	if (info->f_sign)
		info->f_blank = OFF;
}
