/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/13 18:35:40 by joalmeid         ###   ########.fr       */
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

	pid = getpid();
	printf("PID: %d\n", pid);
	signal(SIGUSR2, sig_handler);
	while(1)
		pause();
}
