/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:59:43 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:35:17 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	str_len;
	char	*res;

	if (!s || !f)
		return (NULL);
	str_len = ft_strlen(s);
	res = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!res)
		return (NULL);
	res[str_len] = '\0';
	while (str_len > 0)
	{
		str_len--;
		res[str_len] = f(str_len, s[str_len]);
	}
	return (res);
}
