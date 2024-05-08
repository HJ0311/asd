/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:10:10 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/31 14:22:04 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// count node
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while (lst != 0)
	{
		lst = lst->next;
		cnt++;
	}
	return (cnt);
}
