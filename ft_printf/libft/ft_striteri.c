/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyehan <hyehan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 07:49:28 by hyehan            #+#    #+#             */
/*   Updated: 2023/10/28 19:22:29 by hyehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// applies 'f' each char of the sting 's'
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
