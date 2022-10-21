/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/21 13:16:54 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_byte[8] = "\0\0\0\0\0\0\0\0";

void	reset_byte(void)
{
	int	i;

	i = 0;
	while(g_byte[i])
	{
		g_byte[i] = '\0';
		i ++;
	}
	g_byte[i] = '\0';
}

void	print_byte(char* bits)
{
	unsigned int	byte;
	unsigned int	i;
	unsigned char	printable;

	byte = 0;
	i = 0;
	printable = '\0';
	while (bits[i])
	{
		byte = ((byte << 1) | (bits[i] - 48));
		i ++;
	}
	printable = byte;
	write(1, &printable, 1);
	reset_byte();
}

void	save_bit(char recived_bit)
{
	unsigned int	i;

	i = 0;
	while (g_byte[i])
		i ++;
	if (i < 8)
	{
		g_byte[i] =  recived_bit;
		i ++;
	}
	if (i >= 8)
	{
		g_byte[8] = '\0';
		i = 0;
		print_byte(g_byte);
	}
}
void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		save_bit('1');
	else if (sig == SIGUSR2)
		save_bit('0');
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("PID: %d\n", pid);
	while(1)
	{
		signal(SIGUSR2, sig_handle);
		signal(SIGUSR1, sig_handle);
		pause();
	}
}
