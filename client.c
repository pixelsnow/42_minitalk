/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:56:16 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 22:52:23 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void signal_handler(int signum)
{
	if (signum)
		ft_printf("Message received!\n");
}

int input_invalid(int ac, char** av)
{
	if (ac != 3 || !av || !av[0] || !av[1] || av[2])
		return (1);
	return (0);
}

int main(int ac, char** av)
{
	int		server_pid;
	char*	message;

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
	kill(server_pid, SIGUSR1);
	signal(SIGUSR1, signal_handler);
	pause();
	return (0);
}

//usleep(100);