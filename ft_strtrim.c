/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:41:44 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/18 17:33:17 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static unsigned char	contains(char const *set, const char c)
{
	while(*set)
		if (*(set++) == c)
			return (1);
	return (0);
}

static unsigned char	matches(char const *set, char const *input)
{
	while (*set == *input)
	{
		if (!contains(set, *input))
			return (1);
		input++;
		if (*set != *input)
			set++;
		else if (!*set)
			return (1);
	}
	return (0);
}

static char *count_noset(size_t *count, char const *s1, char const *set)
{
	size_t	i;
	char	*start;

	i = 0;
	start = (char *)s1;
	while (contains(set, *(s1++)))
		start++;
	while (start[i])
	{
		if (matches(set, start + i))
			return (start);
		if (!contains(set, start[i++]))
			(*count)++;
	}
	return (start);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	count;
	char	*start;
	char	*buffer;

	i = 0;
	count = 0;
	if (s1 == 0 || *s1 == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	start = count_noset(&count, s1, set);
	buffer = (char *)ft_calloc(count + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (i < count)
	{
		buffer[i] = start[i];
		i++;
	}
	return (buffer);
}
