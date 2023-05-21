/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:18:18 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/21 17:29:48 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int read_len(int signo, int len)
{
	len = len >> 1;
	if (signo == SIGUSR2)
		len = len | (1 << 30);
	return len;
}

static void    signal_handler(int signo, siginfo_t *info, void *context)
{
	static int	len = 0;
	static int	i = 0;
	static char	*res;

	if (i < 31)
	{
		len = read_len(signo, len);
	}
	else if (i == 31) {
		//ft_printf("LEN: %i\n", len);
		res = (char *)malloc((len + 1) * sizeof(char));
		if (!res)
		{
			ft_printf("ERROR: memory not allocated\n");
		}
		res[len] = '\0';
	}
	else if (i > 31 && i <= len * 8 + 32)
	{
		if (signo == SIGUSR2)
		{
			//ft_printf("1 to %ith bit of %ith char\n", (i - 32) % 8, (i - 32) / 8);
			res[(i - 32) / 8] |= (1 << (7 - (i - 32) % 8));
			//ft_printf("res[%i] |= %i\n", (i - 32) / 8, res[(i - 32) / 8 - 1] | (1 << (7 - (i - 32) % 8)));
			//ft_printf("res[%i]: %i\n",(i - 32) / 8, res[(i - 32) / 8]);
		}
		else
		{
			//ft_printf("0 to %ith bit of %ith char\n", (i - 32) % 8, (i - 32) / 8);
		}
	}
	i++;
	if (i == len * 8 + 32)
	{
		ft_printf("%s\n", res);
		kill(info->si_pid, SIGUSR1);
		free(res);
		res = NULL;
		len = 0;
		i = 0;
	}
	(void)context;
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
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
 	while (1)
		pause();
	return (0);
}