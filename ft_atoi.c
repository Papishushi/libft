/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 19:07:52 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_lenght(const char *nptr, size_t *len)
{
	int	hassymbol;

	hassymbol = 0;
	while (nptr && *nptr)
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

int	ft_atoi(const char *nptr)
{
	size_t	len;
	size_t	i;
	char	*start;
	int		factor;
	int		result;

	i = 1;
	factor = 1;
	result = 0;
	len = 0;
	start = get_lenght(nptr, &len);
	while (i++ < len)
		factor *= 10;
	i = 0;
	while (i < len)
	{
		result += ((int)start[i++] - 48) * factor;
		factor *= 0.1f;
	}
	if (*(start - 1) == '-')
		result *= -1;
	return (result);
}
