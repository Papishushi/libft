/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:56:36 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 14:40:07 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sc;
	unsigned char	cc;

	i = 0;
	sc = (unsigned char *)s;
	cc = (unsigned char)c;
	while (i < n)
	{
		if (sc[i] == cc)
			return (sc + i);
		i++;
	}
	return (0);
}
