/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 19:26:17 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	update_count(const char **s, size_t i, \
						size_t len, size_t *count)
{
	if (s[0][i] == s[1][len - *count])
	{
		(*count)--;
		return (1);
	}
	return (0);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	len;
	size_t	count;

	i = 0;
	len = ft_strlen(s2);
	count = len;
	if (*s2 == 0)
		return ((char *)s1);
	while (i < n && s1[i])
	{
		if (!update_count((const char *[]){s1, s2}, i, len, &count))
		{
			count = len;
			update_count((const char *[]){s1, s2}, i, len, &count);
		}
		if (count == 0)
		{
			if (i == len - 1)
				return ((char *)s1);
			return ((char *)s1 + i - len + 1);
		}
		i++;
	}
	return (0);
}
