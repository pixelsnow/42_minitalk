/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:17:29 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/21 22:18:35 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	read_len_bit(int signo, int len)
{
	len = len >> 1;
	if (signo == SIGUSR2)
		len = len | (1 << 30);
	return (len);
}

static char	*malloc_message(int len)
{
	char	*res;

	res = (char *)malloc((len + 1) * sizeof(char));
	ft_bzero(res, len);
	if (!res)
		return (NULL);
	res[len] = '\0';
	return (res);
}

static void	finalise(char **res, pid_t client_pid, int *len, int *i)
{
	ft_printf("%s\n", *res);
	kill(client_pid, SIGUSR1);
	free(*res);
	*res = NULL;
	*len = 0;
	*i = 0;
}

static void	signal_handler(int signo, siginfo_t *info, void *context)
{
	static int	len = 0;
	static int	i = 0;
	static char	*res;

	if (i < 31)
		len = read_len_bit(signo, len);
	else if (i < 32)
	{
		res = malloc_message(len);
		if (!res)
		{
			ft_putstr_fd("ERROR: memory allocation failed\n", 2);
			exit(1);
		}
	}
	else if (i <= len * 8 + 32 && signo == SIGUSR2)
			res[(i - 32) / 8] |= (1 << (7 - (i - 32) % 8));
	i++;
	if (i == len * 8 + 32)
		finalise(&res, info->si_pid, &len, &i);
	(void)context;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	action;

	pid = getpid();
	ft_printf("Server process id: %i\n", pid);
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	action.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
