/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:57:27 by hyehan            #+#    #+#             */
/*   Updated: 2024/02/01 16:05:13 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		print_len;

	va_start(ap, format);
	print_len = ft_parse_format(format, ap);
	if (print_len == ERROR)
		return (ERROR);
	va_end(ap);
	return (print_len);
}

int	ft_parse_format(const char *format, va_list ap)
{
	int		print_len;
	t_info	info;

	print_len = 0;
	while (*format != '\0')
	{
		ft_init_info(&info);
		if (*format == '%')
		{
			format++;
			ft_parse_flag(&info, &format);
			ft_parse_width(&info, &format);
			ft_parse_precision(&info, &format);
			print_len += ft_print_type(&info, ap, *format);
		}
		else
			print_len += ft_print_write(&info, *format, 1);
		if (info.f_err == ON)
			return (ERROR);
		format++;
	}
	va_end(ap);
	return (print_len);
}

int	ft_print_type(t_info *info, va_list ap, char specifier)
{
	if (specifier == 'c')
		return (ft_print_c(info, va_arg(ap, int)));
	else if (specifier == 's')
		return (ft_print_s(info, va_arg(ap, char *)));
	else if (specifier == 'p')
		return (ft_print_p(info, va_arg(ap, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_di(info, va_arg(ap, int)));
	else if (specifier == 'u')
		return (ft_print_u(info, va_arg(ap, unsigned int)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_x(info, va_arg(ap, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_print_pct(info));
	else
		info->f_err = ON;
	return (0);
}

void	ft_init_info(t_info *info)
{
	info->width = -1;
	info->prec = -1;
	info->f_left = OFF;
	info->f_zero = OFF;
	info->f_hash = OFF;
	info->f_blank = OFF;
	info->f_sign = OFF;
	info->f_dot_only = OFF;
	info->f_err = OFF;
	info->num_sign = 1;
}

int	ft_print_write(t_info *info, char c, int size)
{
	int	tmp;
	int	print_len;

	print_len = 0;
	tmp = 0;
	while (size-- > 0)
	{
		tmp = write(1, &c, 1);
		if (tmp == ERROR)
			info->f_err = ON;
		print_len += tmp;
	}
	return (print_len);
}
