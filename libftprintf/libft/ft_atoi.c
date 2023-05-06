/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 20:10:08 by vvagapov          #+#    #+#             */
/*   Updated: 2022/11/12 22:19:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static char	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\r' || c == '\n' || c == '\v'
		|| c == '\f');
}

int	ft_atoi(const char *str)
{
	char		sign;
	long long	res;
	long long	res_prev;

	sign = 1;
	res = 0;
	while (is_whitespace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*(str++) == '-')
			sign = -1;
	while (*str >= '0' && *str <= '9')
	{
		res_prev = res;
		res = res * 10 + (*(str++) - '0');
		if ((res_prev ^ res) < 0)
		{
			if (sign > 0)
				return (-1);
			return (0);
		}
	}
	return ((int)res * sign);
}
