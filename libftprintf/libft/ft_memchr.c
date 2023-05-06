/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 16:37:54 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:36:49 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	uc;
	unsigned char	*str;
	size_t			i;

	i = 0;
	uc = (unsigned char)c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == uc)
			return (str + i);
		i++;
	}
	return (NULL);
}
