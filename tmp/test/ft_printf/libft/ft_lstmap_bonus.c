/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 03:03:36 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/31 15:38:18 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* applies 'f' on the content of each node and copy new list.
'del' is used to delete content of node if needed */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*newnode;
	void	*content;

	node = NULL;
	while (lst != 0)
	{
		content = f(lst->content);
		newnode = ft_lstnew(content);
		if (newnode == NULL)
		{
			del(content);
			ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, newnode);
		lst = lst->next;
	}
	newnode = NULL;
	return (node);
}
