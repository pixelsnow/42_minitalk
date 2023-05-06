/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:08:17 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:55:29 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Return value:
            The new string.
            NULL if the allocation fails.
External functs.
            malloc
Description:
            Allocates (with malloc(3)) and returns a new
            string, which is the result of the concatenation
            of ’s1’ and ’s2’.
*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = malloc(sizeof(char) * (s1_len + s2_len) + 1);
	if (!res)
		return (NULL);
	res[s1_len + s2_len] = '\0';
	while (s2_len)
	{
		s2_len--;
		res[s1_len + s2_len] = s2[s2_len];
	}
	while (s1_len)
	{
		s1_len--;
		res[s1_len] = s1[s1_len];
	}
	return (res);
}
