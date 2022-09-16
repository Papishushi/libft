/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 00:21:11 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	factor;
	size_t	len;
	size_t	i;
	int		result;

	i = 0;
	result = 0;
	len = ft_strlen(nptr);
	factor = 1;
	while (i++ < len)
		factor *= 10;
	i = 0;
	while (i < len)
	{
		result += (nptr[i++] - '0') * factor;
		factor *= 0.1f;
	}
	return (result);
}
