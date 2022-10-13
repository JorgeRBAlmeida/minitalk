/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:14:05 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/06 16:11:23 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
	{
		printf("invalid number of arguments!");
	}
	pid = atoi(argv[1]);
	kill(pid, SIGUSR2);
	return (0);
}
