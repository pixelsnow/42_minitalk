/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:09:36 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 23:05:53 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*res;
	size_t	num_of_bytes;

	num_of_bytes = size * count;
	if (size && count && (num_of_bytes % size || num_of_bytes % count))
		return (NULL);
	res = malloc(num_of_bytes);
	if (!res)
		return (NULL);
	ft_bzero(res, num_of_bytes);
	return ((void *)res);
}
