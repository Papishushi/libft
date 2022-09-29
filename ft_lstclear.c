/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:15:18 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/29 17:57:07 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	ft_sp_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	f(lst->content);
	if (lst->next)
		ft_sp_lstiter(lst->next, f);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	ft_sp_lstiter(*lst, del);
	*lst = (void *)0;
}
