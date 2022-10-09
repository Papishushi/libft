/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 21:05:14 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/26 17:40:00 by dmoliner         ###   ########.fr       */
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
		if (*nb < 10)
		{
			temp = *nb + '0';
			buffer[1] = temp;
			return (0);
		}
		return  (2);
	}
	else if (*nb < 10)
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
	size_t	lenght;
	size_t	i;

	i = 0;
	lenght = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n == INT_MAX)
		return (ft_strdup("2147483647"));
	ft_memset(reverse_buffer, 0, 12 * sizeof(char));
	ft_memset(buffer, 0, 12 * sizeof(char));
	if (!ft_putnbr_sp(&n, buffer))
		return (ft_strdup(buffer));
	if (buffer[0] == '-')
		i++;
	while (n >= 1)
	{
		reverse_buffer[lenght++] = (n % 10) + '0';
		n /= 10;
	}
	while (i <= lenght)
	{
		if (buffer[0] == '-')
			buffer[i] = reverse_buffer[lenght - i];
		else
			buffer[i] = reverse_buffer[lenght - i - 1];
		i++;
	}
	return (ft_strdup(buffer));
}
