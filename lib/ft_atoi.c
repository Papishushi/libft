/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/30 16:44:12 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_lenght(const char *nptr, size_t *len)
{
	char	hassymbol;

	hassymbol = 0;
	while (*nptr)
	{
		if (*nptr && !(*len) && !ft_isalnum(*nptr))
		{
			if (hassymbol)
				break ;
			if (*nptr == '-' || *nptr == '+')
				hassymbol = 1;
			nptr++;
			continue ;
		}
		else if (ft_isdigit(*nptr))
			(*len)++;
		else
			break ;
		nptr++;
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
	char			isneg;
	char			*start;
	unsigned long	result;

	if (!nptr)
		return (0);
	i = 0;
	result = 0;
	len = 0;
	start = get_lenght(nptr, &len);
	isneg = *(start - 1) == '-';
	while (i < len)
	{
		result += (start[len - i - 1] - 48) * ft_pow10(i);
		i++;
		if (result > LONG_MAX && isneg)
			return (-1);
		else if (result > LONG_MAX)
			return (0);
	}
	if (isneg)
		return (result * -1);
	return (result);
}
