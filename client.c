/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:56:16 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 23:46:48 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <limits.h>

static void signal_handler(int signum)
{
	if (signum)
		ft_printf("Message received!\n");
	
}

static int input_invalid(int ac, char** av)
{
	if (ac != 3 || !av || !av[0] || !av[1] || !av[2])
		return (1);
	return (0);
}

static int send_len(int server_pid, int len)
{
	int	i;

	i = 0;
	//len = INT_MAX;
	while (i < 32)
	{
		//ft_printf("len: %i\n", len);
		if (len & 1)
		{

			kill(server_pid, SIGUSR2);
		}
		else
		{
			kill(server_pid, SIGUSR1);
		}
		len = len >> 1;
		usleep(DELAY);
		i++;
	}
	return (0);
}

int main(int ac, char** av)
{
	int		server_pid;
	char*	message;
	int		len;

	ft_printf("31: %i\n", 1 << 31);
	ft_printf("30: %i\n", 1 << 30);
	ft_printf("29: %i\n", 1 << 29);
	ft_printf("1: %i\n", 1 << 1);
	if (input_invalid(ac, av))
	{
		ft_printf("Please provide server process id and your message\n");
		return (1);
	}
	server_pid = ft_atoi(av[1]);
	if (kill(server_pid, 0))
	{
		ft_printf("Process with this id doesn't exist\n");
		return (1);
	}
	message = av[2];
	len = ft_strlen(message);
	signal(SIGUSR1, signal_handler);
	send_len(server_pid, len);
	//kill(server_pid, SIGUSR1);
	pause();
	ft_printf("pause\n");
	return (0);
}

//usleep(100);