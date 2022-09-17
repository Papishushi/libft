/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 03:38:59 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	len;
	size_t	i;
	int	factor;
	int		result;

	i = 1;
	factor = 1;
	result = 0;
	len = ft_strlen(nptr);
	while (i++ < len)
		factor *= 10;
	i = 0;
	while (i < len)
	{
		result += ((int)nptr[i++] - 48) * factor;
		factor *= 0.1f;
	}
	return (result);
}
