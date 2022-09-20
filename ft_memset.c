/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:56:48 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 14:42:58 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*bc;
	unsigned char	cc;

	i = 0;
	bc = (unsigned char *)b;
	cc = (unsigned char)c;
	while (i < len)
		bc[i++] = cc;
	return (b);
}
