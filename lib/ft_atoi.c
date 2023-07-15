/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:18:49 by dmoliner          #+#    #+#             */
/*   Updated: 2023/01/08 18:18:51 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		neg;

	num = 0;
	neg = 1;
	i = 0;
	while ((str[i] <= 13 && str[i] >= 9) || str[i] == 32)
		i++;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && (str[i] <= '9' && str[i] >= '0'))
	{
		if (num * neg > INT_MAX)
			return (-1);
		else if (num * neg < INT_MIN)
			return (0);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((int)num * neg);
}
