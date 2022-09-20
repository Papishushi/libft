/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:01:26 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/18 18:01:26 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static size_t	get_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			count++;
		if (s[i++] == c && s[i] != c)
			count++;
	}
	return (count);
}

static char	*cutstr(char const *s, char c)
{
	size_t	i;
	size_t	count;
	char	*sc;
	char	*buff;

	i = 0;
	sc = (char *)s;
	count = 0;
	if (!ft_strchr(s, c))
		return (ft_strdup(s));
	while (*(sc++) != c)
		count++;
	if (count == 0)
		return (ft_calloc(1, sizeof(char)));
	sc = (char *)s;
	buff = ft_calloc(count + 1, sizeof(char));
	while (i < count)
		buff[i++] = *(sc++);
	return (buff);
}

static void mainprocess(char const *s, char c, char	**buff)
{
	size_t	i;
	size_t	count;
	char	*temp;

	i = 0;
	count = get_count(s, c);
	if (count == 1)
		count++;
	if (*s != c)
	{
		buff[i++] = cutstr(s, c);
		if (count == 2)
			return;
	}
	while(i < count)
	{
		temp = ft_strchr(s, c) + 1;
		while (*temp && *temp == c)
			temp++;
		buff[i++] = cutstr(temp, c);
		s = temp;
	}
	buff[count - 1] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;

	if (*s == 0)
		return (ft_calloc(1, sizeof(char *)));
	if (c == '\0' || !ft_strchr(s, c))
	{
		buffer = ft_calloc(2, sizeof(char *));
		buffer[0] = ft_strdup(s);
		return (buffer);
	}
	buffer = ft_calloc(get_count(s, c), sizeof(char *));
	mainprocess(s, c, buffer);
	return (buffer);
}
