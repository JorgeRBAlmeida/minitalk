#include "minitalk.h"

#include <stdlib.h>

int	main(int argc, char* argv[])
{
	int	pid;
	
	pid = 0;
	if (argc == 2)
	{
		pid = atoi(argv[1]);
		kill(SIGUSR1, pid);
	}
	return (0);
}

