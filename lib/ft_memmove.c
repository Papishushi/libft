/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/10/05 11:48:10 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	size_t			count;
	unsigned char	*srcc;
	unsigned char	*dstc;

	if (src == dst)
		return (dst);
	i = 0;
	srcc = (unsigned char *)src;
	dstc = (unsigned char *)dst;
	count = dstc - srcc;
	while (i < len)
	{
		if (srcc < dstc && srcc <= dstc + len)
		{
			if (i >= count)
				return (dst);
			else if (i + count < len)
				dstc[i + count] = dstc[i];
		}
		dstc[i] = srcc[i];
		i++;
	}
	return (dst);
}
