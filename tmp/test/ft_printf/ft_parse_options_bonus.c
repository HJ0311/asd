/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_options_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:25:14 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/28 14:26:49 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_flag(t_info *info, const char **str)
{
	while (isflag(**str))
	{
		if (**str == '-')
			info->f_left = ON;
		else if (**str == '0')
			info->f_zero = ON;
		else if (**str == '#')
			info->f_hash = ON;
		else if (**str == ' ')
			info->f_blank = ON;
		else if (**str == '+')
			info->f_sign = ON;
		(*str)++;
	}
}

void	ft_parse_width(t_info *info, const char **str)
{
	if (ft_isdigit(**str))
		info->width = ft_atoi_mini(str);
}

void	ft_parse_precision(t_info *info, const char **str)
{
	if (**str == '.')
	{
		(*str)++;
		if (ft_isdigit(**str))
			info->prec = ft_atoi_mini(str);
		else
			info->f_dot_only = ON;
	}
}
