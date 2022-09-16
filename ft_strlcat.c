/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmoliner <dmoliner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:54:39 by dmoliner          #+#    #+#             */
/*   Updated: 2022/09/17 00:54:40 by dmoliner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	size_t	maxappend;

	oglen = ft_strlen(dst);
	maxappend = size - oglen - 1;
	i = oglen;
	while (i < oglen + size)
	{
		dst[i] = src[i - oglen];
		if ((i - oglen) >= maxappend || dst[i] == '\0')
			return (oglen + ft_strlen(src));
		i++;
	}
	return (ft_strlen(src));
}
