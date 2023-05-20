/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:18:18 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 23:45:46 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void    signal_handler(int signo, siginfo_t *info, void *context)
{
	static int	receiver = 0;
	static int	i = 0;

	if (i < 31)
	{
		
		if (signo == SIGUSR2)
		{
			ft_printf("1\n");
			receiver = receiver | (1 << 30);
		}
		else
		{
			ft_printf("0\n");
		}
		ft_printf("%ith bit - receiver: %i\n", i, receiver);
		if (i == 30)
		{
			ft_printf("RESULT: %i\n", receiver);
			kill(info->si_pid, SIGUSR1);
		}
		else
			receiver = receiver >> 1;
		i++;
	}
	(void)context;
	/* if (i == 32)
		{
			ft_printf("RESULT: %i\n", receiver);
			kill(info->si_pid, SIGUSR1);
		} */
}

int	main(void)
{
	int 				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("Server process id: %i\n", pid);
	sigemptyset(&action.sa_mask); // this init is required before using sigset_t
	action.sa_flags = SA_SIGINFO; // sa_sigaction is pointed at handler function
	action.sa_sigaction = signal_handler; // setting handler
	
 	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}