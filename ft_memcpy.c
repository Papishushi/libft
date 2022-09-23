/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:56:42 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/21 15:59:11 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*srcc;
	unsigned char	*dstc;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	while (i++ < n)
		*(dstc++) = *(srcc++);
	return (dst);
}
