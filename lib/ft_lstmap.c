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
	t_list	**buffer;
	t_list	*result;
	int		len;
	int		i;

	if (!lst || !f || !del)
		return ((void *)0);
	i = 0;
	len = ft_lstsize(lst);
	if (!len)
		return ((void *)0);
	buffer = ft_calloc(len, sizeof(t_list *));
	while (i < len)
	{
		buffer[i] = ft_lstnew(f(lst->content));
		if (i != 0)
			buffer[i - 1]->next = buffer[i];
		i++;
		lst = lst->next;
	}
	result = *buffer;
	del(buffer);
	return (result);
}
