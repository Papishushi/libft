/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 12:53:48 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/28 12:53:48 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*result;

	result = ft_calloc(1, sizeof(t_list));
	if (!result)
		return ((void *)0);
	result->content = 0;
	if (content)
		result->content = content;
	result->next = (void *)0;
	return (result);
}
