/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 23:14:48 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:56:03 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	res;

	res = (unsigned char)c;
	if (res >= 'A' && res <= 'Z')
		return (c + 'a' - 'A');
	else
		return (c);
}
