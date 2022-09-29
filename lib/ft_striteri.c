/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 00:27:50 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/22 02:27:34 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;
	size_t	lenght;

	if (s == 0 || f == 0)
		return ;
	i = 0;
	lenght = ft_strlen(s);
	while (i < lenght)
	{
		f(i, s + i);
		i++;
	}
	return ;
}
