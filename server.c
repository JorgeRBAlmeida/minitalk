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

char	g_byte[8] = "\0\0\0\0\0\0\0";

void	print_byte(char* bits)
{
	int	byte;
	int	i;

	byte = 0;
	i = 0;
	while (bits[i])
	{
		byte = ((byte << 1) | (bits[i] - 48));
		i ++;
	}
	write(1, &byte, 4);
}

void	send_bit(char recived_bit)
{
	int	i;

	i = 0;
	while (g_byte[i])
	{
		i ++;
	}
	if (i < 8)
		g_byte[i] =  recived_bit;
	else if (i == 8)
	{
		g_byte[i] = '\0';
		i = 0;
		print_byte(g_byte);
	}
	
}
void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		{
		send_bit('1');
	}
	else
	{
		send_bit('0');
	}
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
