/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:18:17 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:55:32 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Go through the string until the end or until the match is found.
// If needle wasn't '\0' and nothing was found, return NULL,
// Otherwise return result (end of the string in case of '\0')

char	*ft_strchr(const char *s, int c)
{
	char	needle;
	char	*res;

	needle = (char)c;
	res = (char *)s;
	while (*res && *res != needle)
		res++;
	if (!*res && needle)
		return (NULL);
	else
		return (res);
}
