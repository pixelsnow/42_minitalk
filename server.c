/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:18:18 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 22:26:46 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/* static void sig_handler(int signum)
{
	ft_printf("got your message %i\n", signum);
} */

void    signal_handler(int signo, siginfo_t *info, void *context)
{
	ft_printf("signo %i\n", signo);
	(void)context;
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	int 				pid;
	struct sigaction	action;

	ft_printf("hello\n");
	pid = getpid();
	ft_printf("Server process id: %i\n", pid);
	//signal(SIGUSR2, sig_handler);
	sigemptyset(&action.sa_mask); // this init is required before using sigset_t
	action.sa_flags = SA_SIGINFO; // sa_sigaction is pointed at handler function
	action.sa_sigaction = signal_handler; // setting handler
	
 	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		ft_printf("pause\n");
		pause();
	}
	return (0);
}