/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:36:08 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 21:23:36 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "unistd.h"

void	ft_putnbr_fd(int n, int fd)
{
	size_t	len;
	char	*parsed;

	parsed = ft_itoa(n);
	len = ft_strlen(parsed);
	write(fd, parsed, len);
}
