/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:05 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/18 15:08:17 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void	handle_arg(char* str, int pid)
{
	int i;
	int	y;
	
	i = 0;
	y = 7;
	while (str[i])
	{
		y = 7;
		while (y >= 0) 
		{ 
			if ((str[i] >> y)  & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			y--;
			usleep(280);
		}
		i++;	
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		handle_arg(argv[2], pid);
	}
	else
		printf("Error! The program needs 3 arguments to work correctly.");
	return (0);
}
