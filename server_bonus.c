/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joalmeid <joalmeid@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:22:28 by joalmeid          #+#    #+#             */
/*   Updated: 2022/10/26 01:32:13 by joalmeid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

unsigned int g_byte[2] = {0, 0};

void	sig_handle(int sig)
{
	if (sig == SIGUSR1)
		g_byte[0] = ((g_byte[0] << 1) | 1);
	else if (sig == SIGUSR2)
		g_byte[0] = (g_byte[0] << 1);
	g_byte[1] += 1;
	if (g_byte[1] == 8)
	{
		ft_putchar_fd(g_byte[0], 1);
		g_byte[1] = 0;
		g_byte[0] = 0;
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
