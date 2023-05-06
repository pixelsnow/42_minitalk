/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:43:37 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/21 17:40:09 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// First the function looks for terminating 0 in dst.
// If 0 wasn't found within the buffer size, stop.
// Go through src string until it's over or
// until the buffer is over and copy to dst.
// Place the terminating zero if buffer is large enough.
// Calculate length of src string.
// Return sum of src length and either dst length
// or dstsize, if dst length was longer than buffer.

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	while ((dst_len < dstsize) && dst[dst_len])
		dst_len++;
	i = 0;
	while ((dst_len + i + 1) < (dstsize) && src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < dstsize)
		dst[dst_len + i] = '\0';
	while (src[i])
		i++;
	return (i + dst_len);
}
