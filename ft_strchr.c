/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 01:34:00 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!ft_isascii(c) && c)
		return ((char	*)s);
	while (s[i])
	{
		if (s[i] == c)
			return ((char	*)s + i);
		i++;
	}
	if (c == 0)
		return ((char	*)s + i);
	return (0);
}
