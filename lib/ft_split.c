/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 18:01:26 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/30 21:26:28 by dmoliner         ###   ########.fr       */
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
		if (s[i] != c && s[i + 1] == 0)
			count++;
		if (s[i++] == c && (s[i] != c || s[i] == 0))
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

static void	cutloop(char const *s, char c, char	**buff, size_t count)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (i < count)
	{
		temp = ft_strchr(s, c) + 1;
		while (*temp && *temp == c)
			temp++;
		if (!temp || !*temp)
			break ;
		if (!ft_strchr(temp, c))
		{
			buff[i] = ft_strdup(temp);
			break ;
		}
		buff[i++] = cutstr(temp, c);
		s = temp;
	}
}

static void	mainprocess(char const *s, char c, char	**buff)
{
	size_t	count;

	count = get_count(s, c);
	buff[count - 1] = 0;
	if (*s != c)
	{
		*(buff++) = cutstr(s, c);
		if (count == 2)
			return ;
	}
	cutloop(s, c, buff, count);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer;

	if (!s)
		return (0);
	if (*s == 0)
	{
		buffer = ft_calloc(1, sizeof(char *));
		buffer[0] = 0;
		return (buffer);
	}
	if (c == '\0' || !ft_strchr(s, c))
	{
		buffer = ft_calloc(2, sizeof(char *));
		buffer[0] = ft_strdup(s);
		buffer[1] = 0;
		return (buffer);
	}
	buffer = ft_calloc(get_count(s, c), sizeof(char *));
	if (!buffer)
		return (0);
	mainprocess(s, c, buffer);
	return (buffer);
}
