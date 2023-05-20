/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 21:56:16 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 22:25:47 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void sig_handler(int signum)
{
	ft_printf("confirmation %i\n", signum);
}

int main(int ac, char** av)
{
	int		pid;
	int		serverPid;
	char*	message;

	if (ac != 3)
	{
		ft_printf("Please provide server process id and your message\n");
		return (1);
	}
		
	pid = getpid();
	ft_printf("Client process id is: %i\n", pid);

	serverPid = ft_atoi(av[1]);
	message = av[2];
	kill(serverPid, SIGUSR1);
	signal(SIGUSR1, sig_handler);
	pause();
	return (0);
}

//usleep(100);