/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/26 09:58:40 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handle(int sig)
{
	static unsigned int	byte_to_print = 0;
	static unsigned int	bit_count = 0;

	if (sig == SIGUSR1)
		byte_to_print = ((byte_to_print << 1) | 1);
	else if (sig == SIGUSR2)
		byte_to_print = (byte_to_print << 1);
	bit_count += 1;
	if (bit_count == 8)
	{
		ft_putchar_fd(byte_to_print, 1);
		byte_to_print = 0;
		bit_count = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	signal(SIGUSR1, sig_handle);
	signal(SIGUSR2, sig_handle);
	while (1)
		pause();
}
