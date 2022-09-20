/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:05:14 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 21:22:12 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_sp(int *nb, char *buffer)
{
	char	temp;

	if (*nb < 0)
	{
		*nb *= -1;
		buffer[0] = '-';
	}
	if (*nb < 10)
	{
		temp = *nb + '0';
		buffer[0] = temp;
		return (0);
	}
	return (1);
}

char	*ft_itoa(int n)
{
	char	buffer[12];
	char	reverse_buffer[12];
	int		lenght;
	int		i;

	lenght = 0;
	ft_bzero(reverse_buffer, 11);
	if (!ft_putnbr_sp(&n, buffer))
		return (ft_strdup(buffer));
	i = 0;
	while (n >= 1)
	{
		reverse_buffer[lenght++] = (n % 10) + '0';
		n /= 10;
	}
	while (i <= lenght)
	{
		buffer[i] = reverse_buffer[lenght - 1 - i];
		i++;
	}
	return (ft_strdup(buffer));
}
