/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:19:34 by dmoliner          #+#    #+#             */
/*   Updated: 2023/01/08 18:19:36 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	trimornot(char const *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	len;

	i = 0;
	if (!s1 || !set)
		return (0);
	start = 0;
	end = ft_strlen(s1);
	while (trimornot(set, s1[start]) == 1)
		start++;
	while (end > start && trimornot(set, s1[end - 1]) == 1)
		end--;
	len = end - start;
	str = ft_calloc(sizeof(*s1), (len + 1));
	if (!str)
		return (0);
	while (i < len)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
