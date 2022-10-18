/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/18 14:53:56 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(void)
{
	pid_t				pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while(1)
	{
		signal(SIGUSR2, sig_handle);
		signal(SIGUSR1, sig_handle);
		pause();
	}
}
