/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:15:18 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/28 14:20:20 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int	i;
	int	len;

	if (!lst || !del)
		return ;
	i = 0;
	len = ft_lstsize(*lst);
	while (i < len)
		del(lst[i++]);
}
