/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:15:18 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/30 09:46:11 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;
	t_list	*to_free;

	if (!lst || !del)
		return ;
	temp = *lst;
	while (temp)
	{
		del(temp->content);
		to_free = temp;
		temp = temp->next;
		free(to_free);
	}
	*lst = (void *)0;
}
