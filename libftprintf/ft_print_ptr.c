/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:25:31 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 21:37:34 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_long_hex(unsigned long int n)
{
	if (n < 16)
		return (print_hex_char(n, 1));
	else
		return (print_long_hex(n / 16) + print_hex_char(n % 16, 1));
}

int	print_pointer(void *p)
{
	return (write(1, "0x", 2) + print_long_hex((unsigned long int)p));
}
