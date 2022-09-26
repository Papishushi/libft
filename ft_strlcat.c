/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/26 18:19:59 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cat_loop(size_t *i, char *dst, const char *src, size_t size)
{
	size_t	maxappend;
	size_t	oglen;
	size_t	temp;

	temp = 0;
	oglen = ft_strlen(dst);
	*i = oglen;
	maxappend = size - oglen;
	while (*i < oglen + size)
	{
		if (*i != oglen + size - 1)
			dst[*i] = src[*i - oglen];
		if ((*i - oglen) > maxappend || !dst[*i])
			return (oglen + ft_strlen(src));
		else if ((*i - oglen) <= oglen && (*i - oglen))
		{
			if (size > oglen && size)
				(*i)++;
			break ;
		}
		(*i)++;
	}
	return (temp);
}

/// @brief Appends the string src into dst ensuring a null terminatted sequence
/// @brief (as long as there is at least one byte free in dst).
/// @brief ft_strlcat() only operate on true ''C'' strings. This means that both
/// @brief src and dst must be NUL-terminated.
/// @param dst The null terminatted string/buffer to append into.
/// @param src The null terminatted string to append.
/// @param size The full size of the buffer.
/// @return By default the initial length of dst plus the length of src, if size
/// @return is 0 it will return src lenght.
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	oglen;
	size_t	temp;

	oglen = ft_strlen(dst);
	i = oglen;
	temp = cat_loop(&i, dst, src, size);
	if (temp)
		return (temp);
	if (i > 1)
		dst[i - 1] = 0;
	if (size <= oglen && size)
		return (ft_strlen(src) + size);
	else if (size > oglen && size)
		return (ft_strlen(src) + oglen);
	return (ft_strlen(src));
}
