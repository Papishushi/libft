/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 00:58:08 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	size_t			len;
	size_t			count;

	i = 0;
	len = ft_strlen(s2);
	count = len;
	if (*s2 == 0)
		return ((char	*)s1);
	while (i < n)
	{
		if (s1[i] == s2[i])
			count--;
		else
			count = len;
		if (count == 0)
			return ((char	*)s1 + i);
		i++;
	}
	return (0);
}
