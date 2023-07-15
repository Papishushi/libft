/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 18:19:02 by dmoliner          #+#    #+#             */
/*   Updated: 2023/01/08 18:21:25 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	spe_putnbr(int nb)
{
	unsigned int	number;

	number = nb;
	if (number == 0)
		return (0 + '0');
	if (number > 0)
	{
		spe_putnbr(number / 10);
		number %= 10;
	}
	return (number + '0');
}

static int	is_neg(int nb)
{
	if (nb < 0)
		return (1);
	return (0);
}

static size_t	get_len(int n)
{
	size_t			len;
	unsigned int	number;

	len = 0;
	if (is_neg(n))
	{
		number = (unsigned int)-n;
		len++;
	}
	else
		number = (unsigned int)n;
	while (number > 9)
	{
		number /= 10;
		len++;
	}
	len++;
	return (len);
}

char	*ft_itoa(int n)
{
	char			*result;
	size_t			len;
	unsigned int	num;
	int				i;

	len = get_len(n);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	if (is_neg(n))
		num = (unsigned int)-n;
	else
		num = (unsigned int)n;
	while (i++ <= (int)len - 1)
	{
		result[(int)len - i] = spe_putnbr(num);
		num /= 10;
	}
	if (is_neg(n))
		result[0] = '-';
	result[len] = '\0';
	return (result);
}
