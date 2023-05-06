/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 21:41:33 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 23:06:13 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;

	len = ft_strlen(s1);
	s2 = malloc(sizeof(char) * len + 1);
	if (!s2)
		return (NULL);
	s2[len] = '\0';
	while (len)
	{
		len--;
		s2[len] = s1[len];
	}
	return (s2);
}
