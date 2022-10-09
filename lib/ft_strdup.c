/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/10/05 11:37:13 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*buff;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (!len)
		return (ft_calloc(1, sizeof(char)));
	buff = ft_calloc(len + 1, sizeof(char));
	if (!buff)
		return (0);
	while (i < len)
	{
		buff[i] = s[i];
		i++;
	}
	return (buff);
}
