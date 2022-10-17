/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:05 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/17 20:36:37 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void	handle_arg(char* str, int pid)
{
	int i;
	int	y;
	
	i = 0;
	y = 0;
	while (str)
	{
		// function to use biwise -- bishift
		while (y <= 7) 
		{
			if ((str[i] >> y)  & 1)
				kill(SIGUSR1, pid);
			else	
				kill(SIGUSR2, pid);
			y ++;
		}
		i ++;	
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
