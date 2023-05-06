/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 22:18:20 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:56:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters:
            s: The string from which to create the substring.
            start: The start index of the substring in the
                string ’s’.
            len: The maximum length of the substring.
Return value:
            The substring.
            NULL if the allocation fails.
External functs.:
            malloc
Description:
            Allocates (with malloc(3)) and returns a substring
            from the string ’s’.
            The substring begins at index ’start’ and is of
            maximum size ’len’.
*/

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	res_len;
	char	*res;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		res_len = 0;
	else
		res_len = min(len, s_len - start);
	if (res_len < 0)
		res_len = 0;
	res = malloc(sizeof(char) * res_len + 1);
	if (!res)
		return (NULL);
	res[res_len] = '\0';
	while (res_len)
	{
		res_len--;
		res[res_len] = s[start + res_len];
	}
	return (res);
}
