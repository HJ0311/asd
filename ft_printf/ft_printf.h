/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:28:01 by hyehan            #+#    #+#             */
/*   Updated: 2024/02/01 16:12:33 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define SPECIFIER "cspdiuxX%"
# define DEC "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define NULL_STR "(null)"

# define ERROR -1
# define ON 1
# define OFF 0

typedef struct s_info
{
	int		width;
	int		prec;
	int		f_left;
	int		f_zero;
	int		f_hash;
	int		f_blank;
	int		f_sign;
	int		f_dot_only;
	int		f_err;
	int		num_sign;
}	t_info;

/* Main Function */
int		ft_printf(const char *format, ...);
int		ft_parse_format(const char *format, va_list ap);
int		ft_print_type(t_info *info, va_list ap, char specifier);

/* Parsing Function */
void	ft_parse_flag(t_info *info, const char **str);
void	ft_parse_width(t_info *info, const char **str);
void	ft_parse_precision(t_info *info, const char **str);

/* Print Function */
int		ft_print_write(t_info *info, char c, int size);
int		ft_print_c(t_info *info, int c);
int		ft_print_s(t_info *info, char *str);
int		ft_print_p(t_info *info, void *ptr);
int		ft_print_di(t_info *info, long long num);
int		ft_print_u(t_info *info, unsigned int num);
int		ft_print_x(t_info *info, unsigned int num, char s);
int		ft_print_num(t_info *info, char *nbr, int numlen, char specifier);
int		ft_print_sign(t_info *info, char s);
int		ft_print_prefix(t_info *info, char s);
int		ft_print_pct(t_info *info);

/* Extra Function */
void	ft_init_info(t_info *info);
int		isflag(char c);
void	ft_onoff(t_info *info);
int		ft_max(int a, int b);

/* Itoa Function*/
int		ft_atoi_mini(const char **format);
void	ft_itoa_base(size_t num, char *base, char *nbr);
int		cnt_size(size_t num, int lbase);

#endif