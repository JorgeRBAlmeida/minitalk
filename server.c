/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/13 17:34:38 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sig_handler(int sig)
{
	printf("Chegou sigusr1! %d\n", sig);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_sigaction = sig_handler;
	pid = getpid();
	printf("PID: %d\n", pid);
	sigaction(SIGUSR2, &sa, NULL);
	while(1)
		pause();
}
