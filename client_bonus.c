/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:17:42 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/22 14:46:30 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static void	signal_handler(int signum)
{
	if (signum)
		ft_printf("Message received!\n");
}

static int	input_invalid(int ac)
{
	if (ac != 3)
		return (1);
	return (0);
}

static int	send_len(pid_t server_pid, int len)
{
	int	i;

	i = 0;
	while (i < 32)
	{
		if (len & 1)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		len = len >> 1;
		usleep(50);
		i++;
	}
	return (0);
}

static int	send_msg(pid_t server_pid, char *msg, int delay)
{
	int	i;
	int	j;

	i = 0;
	while (msg[i])
	{
		j = 7;
		while (j >= 0)
		{
			usleep(delay);
			if (msg[i] & (1 << j))
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			j--;
		}
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*message;
	int		len;
	int		delay;

	if (input_invalid(ac))
		return (ft_printf("Provide server process id and your message\n"), 1);
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0))
		return (ft_printf("Process with this id doesn't exist\n"), 1);
	message = av[2];
	len = ft_strlen(message);
	delay = 50;
	if (len > 12000)
		delay = 150;
	signal(SIGUSR1, signal_handler);
	send_len(server_pid, len);
	send_msg(server_pid, message, delay);
	pause();
	return (0);
}
