/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:54:06 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/19 22:56:06 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	res;

	res = (unsigned char)c;
	if (res >= 'a' && res <= 'z')
		return (c + 'A' - 'a');
	else
		return (c);
}
