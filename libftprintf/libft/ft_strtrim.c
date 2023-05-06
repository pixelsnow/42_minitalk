/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:26:03 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:55:56 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters:
            s1: The string to be trimmed.
            set: The reference set of characters to trim.
Return value:
            The trimmed string.
            NULL if the allocation fails.
External functs.:
            malloc
Description:
            Allocates (with malloc(3)) and returns a copy of
            ’s1’ with the characters specified in ’set’ removed
            from the beginning and the end of the string.
*/

#include "libft.h"

static char	set_includes_char(char const *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

static size_t	index_start(char const *s1, char const *set)
{
	size_t	res;

	res = 0;
	while (s1[res] && set_includes_char(set, s1[res]))
		res++;
	return (res);
}

static size_t	index_end(char const *s1, char const *set)
{
	size_t	res;

	res = ft_strlen(s1);
	if (!res)
		return (0);
	else
		res--;
	while (res && set_includes_char(set, s1[res]))
		res--;
	return (res);
}

// What shall we do if s1 is NULL?
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_i;
	size_t	end_i;
	size_t	res_len;

	if (!s1 || !set)
		return (NULL);
	start_i = index_start(s1, set);
	end_i = index_end(s1, set);
	if (start_i >= end_i)
		res_len = end_i - start_i;
	else
		res_len = 0;
	return (ft_substr(s1, start_i, res_len + 1));
}
