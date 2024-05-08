/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:20:50 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/30 22:45:49 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// add node to the tail
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cur;

	if (*lst == 0)
		*lst = new;
	else
	{
		cur = ft_lstlast(*lst);
		cur->next = new;
	}
}
