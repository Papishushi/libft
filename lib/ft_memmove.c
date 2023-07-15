/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:17:18 by dmoliner          #+#    #+#             */
/*   Updated: 2023/01/08 18:17:21 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	*lastd;
	unsigned char	*lasts;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		lasts = s + (len - 1);
		lastd = d + (len - 1);
		while (len--)
			*lastd-- = *lasts--;
	}
	return (dst);
}

// int	main(void)
// {
// 	char src[15] = "lorem ipsum";
// 	char dst[20] = "dolor sit amet";
// 	size_t len = 3;

// 	printf("src: %s [ %p ]\n", src, &src);
// 	printf("dst: %s [ %p ]\n", dst, &dst);
// 	printf("-> dst: %s\n", ft_memmove(src, dst, len));
// }
