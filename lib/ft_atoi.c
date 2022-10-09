/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/10/06 01:17:03 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*get_lenght(const char *nptr, size_t *len, int *isneg)
{
	char	hasymb;

	hasymb = 0;
	while (*nptr >= 8 && *nptr <= 32)
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (hasymb++)
			return (0);
		*isneg = 1 - 2 * (*nptr++ == '-');
	}
	while (ft_isdigit(*nptr))
	{
		nptr++;
		(*len)++;
	}
	return ((char *)nptr - *len);
}

static unsigned int	ft_pow10(size_t factor)
{
	unsigned int	result;

	result = 1;
	while (factor--)
		result *= 10;
	return (result);
}

int	ft_atoi(const char *nptr)
{
	size_t			i;
	size_t			len;
	int				isneg;
	char			*start;
	unsigned long	result;

	i = 0;
	result = 0;
	len = 0;
	isneg = 1;
	if (ft_strchr(nptr, '\e'))
		return (0);
	start = get_lenght(nptr, &len, &isneg);
	if (!start)
		return (0);
	while (i < len)
	{
		result += (start[len - i - 1] - 48) * ft_pow10(i);
		if (result > LONG_MAX && isneg == -1)
			return (-1);
		else if (result > LONG_MAX)
			return (0);
		i++;
	}
	return (result * isneg);
}
