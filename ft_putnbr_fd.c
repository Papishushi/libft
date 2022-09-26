/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:36:08 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/26 01:44:57 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include <stdio.h>

size_t	get_len(int n)
{
	size_t	i;
	int		temp;

	i = 0;
	temp = n;
	while (temp >= 1)
	{
		temp /= 10;
		i++;
	}
	return (i);
}

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	size_t	len;
	char	temp[13];
	char	inv[13];

	i = 0;
	len = get_len(n);
	if (len == 0)
		return ;
	temp[12] = 0;
	inv[12] = 0;
	if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
		write(fd, "-", 1);
	while (n >= 1)
	{
		temp[i] = n % 10 + '0';
		inv[len - i] = temp[i];
		if (!(n >= 10))
			inv[len - 1] = n + '0';
		n /= 10;
		i++;
	}
	write(fd, inv, len);
}
