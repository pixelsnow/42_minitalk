/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:23:59 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 19:25:57 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex_char(char n, int lowercase)
{
	if (n < 10)
		return (print_char('0' + n));
	else
		return (print_char('A' - 10 + n + lowercase * ('a' - 'A')));
}

int	print_hex(unsigned int n, int lowercase)
{
	if (n < 16)
		return (print_hex_char(n, lowercase));
	else
		return (print_hex(n / 16, lowercase) + print_hex_char(n % 16,
				lowercase));
}
