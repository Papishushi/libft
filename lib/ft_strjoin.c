/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:04:16 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/26 18:06:49 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	sizeone;
	size_t	sizetwo;
	char	*buffer;

	i = 0;
	j = 0;
	sizeone = ft_strlen(s1);
	sizetwo = ft_strlen(s2);
	buffer = ft_calloc(sizeone + sizetwo + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (i < sizeone)
		buffer[j++] = s1[i++];
	i = 0;
	while (i < sizetwo)
		buffer[j++] = s2[i++];
	return (buffer);
}
