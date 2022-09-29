/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:38:26 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/18 00:32:45 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	temp;
	char	*buffer;

	i = 0;
	if (start > ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	temp = ft_strlen(s + start);
	if (temp > len)
		temp = len;
	buffer = (char *)ft_calloc(temp + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (i < len && s[i + start])
	{
		buffer[i] = s[i + start];
		i++;
	}
	return (buffer);
}
