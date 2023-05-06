/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:39:02 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:55:53 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Go till the end of the string, remember last match if it exists.
// If search was looking for '\0', return address of the end of the string.
// Otherwise return res (NULL or address of the last match)
char	*ft_strrchr(const char *s, int c)
{
	char	needle;
	char	*res;
	char	*temp;

	needle = (char)c;
	temp = (char *)s;
	res = NULL;
	while (*temp)
	{
		if (*temp == needle)
			res = temp;
		temp++;
	}
	if (!needle)
		return (temp);
	else
		return (res);
}
