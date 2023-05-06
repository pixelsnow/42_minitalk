/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 18:26:06 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/23 21:38:25 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_int(int n)
{
	int	minus;

	minus = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (write(1, "-2147483648", 11));
		minus = print_char('-');
		n *= -1;
	}
	if (n < 10)
		return (print_char('0' + n) + minus);
	else
		return (print_int(n / 10) + print_char('0' + n % 10) + minus);
}
