/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:36:08 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/21 19:22:11 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"
#include <stdio.h>

void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;
	size_t	len;
	char	temp[12];
	char	inv[12];

	i = 0;
	len = 0;
	temp[11] = 0;
	inv[11] = 0;
	if (n == -2147483647)
	{
		write(fd, "-2147483647", len);
		return ;
	}
	while (n >= 1)
	{
		temp[i++] = n % 10 + '0';
		n /= 10;
	}
	len = i;
	while (i != 0)
	{
		inv[len - i] = temp[i - 1];
		i--;
	}
	write(fd, inv, len);
}
