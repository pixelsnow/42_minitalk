/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 22:18:18 by vvagapov          #+#    #+#             */
/*   Updated: 2023/05/20 17:58:17 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void sig_handler(int signum)
{
	ft_printf("sig handler in action... %i", signum);
}

int main(void)
{
	int pid;

	pid = getpid();
	ft_printf("Server  process id is: %i", pid);
	signal(SIGUSR1, sig_handler);
	while (1)
	{
		ft_printf("boop");
		sleep(1);
	}
	return 0;
}