#include "minitalk.h"

#include <stdio.h>

void	handle_sig(int sig)
{
	printf("printing sig %d\n", sig);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = &handle_sig;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("PID: %d\n", getpid());
	while (1)
	{
		usleep(100);
	}
}

