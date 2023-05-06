/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:52:45 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:58:42 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Last while loop should really be wrapped in "else" for readability,
// but line limit got me...

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*s;
	char		*d;
	size_t		i;

	if (!src && !dst)
		return (NULL);
	s = src;
	d = dst;
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
		return (dst);
	}
	while (len)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
	return (dst);
}
