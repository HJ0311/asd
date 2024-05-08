/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 18:32:11 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/28 17:53:41 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// is number or alphabet? not 0 : 0
#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
