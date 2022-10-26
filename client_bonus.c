/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:05 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/26 01:32:27 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	handle_arg(char *str, int pid)
{
	int	i;
	int	y;

	i = 0;
	y = 7;
	while (str[i])
	{
		y = 7;
		while (y >= 0)
		{
			if ((str[i] >> y) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			y--;
			usleep(400);
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
		pid = ft_atoi(argv[1]);
		handle_arg(argv[2], pid);
	}
	else
		ft_putstr_fd("Error! The program needs 2 arguments.\n", 1);
	return (0);
}
