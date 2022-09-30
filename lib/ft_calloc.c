/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/30 21:37:28 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*temp;
	void	*buff;

	buff = 0;
	temp = 0;
	if (!size)
		return (malloc(1 * nmemb));
	if (nmemb == 0 ||  size >= ULONG_MAX || \
		nmemb >= ULONG_MAX)
		return ((void *)0);
	temp = malloc(size * nmemb);
	if (temp)
		buff = ft_memset(temp, 0, nmemb * size);
	if (!buff)
		return (0);
	return (buff);
}
