/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:23:43 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/28 14:23:43 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buffer;
	int		len;
	int		i;

	i = 0;
	len = ft_lstsize(lst);
	buffer = ft_calloc(len, sizeof(t_list));
	f(buffer);
	del(buffer);
	i++;
	return (0);
}
