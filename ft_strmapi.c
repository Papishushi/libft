/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 23:14:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/22 00:27:14 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	lenght;
	char	*result;

	if (s == 0 || f == 0)
		return (0);
	i = 0;
	lenght = ft_strlen(s);
	if (lenght == 0)
		return ((char *)ft_calloc(1, sizeof(char)));
	result = (char *)ft_calloc(lenght + 1, sizeof(char));
	if (!result)
		return (0);
	while (i < lenght)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	return (result);
}
