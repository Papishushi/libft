/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:36:08 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/26 18:06:42 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	temp[1];

	temp[0] = n + '0';
	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(fd, "-2147483648", 12);
			return ;
		}
		write (fd, "-", 1);
		n *= -1;
	}
	if (n / 10 > 0)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
	if (ft_isdigit(temp[0]))
		write(fd, temp, 1);
}
