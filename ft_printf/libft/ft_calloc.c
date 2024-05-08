/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:50:31 by hyehan            #+#    #+#             */
/*   Updated: 2023/11/01 16:13:54 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// allocates size bytes of memory and filles zero value
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	arr = malloc(size * count);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, (size * count));
	return (arr);
}
