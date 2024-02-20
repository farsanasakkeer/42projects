/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:41:40 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/11 15:42:45 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int d)
{
	char	c;

	if (d == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (d < 0)
	{
		write (1, "-", 1);
		d = -d;
	}
	if (d >= 0 && d <= 9)
	{
		c = d + '0';
		write (1, &c, 1);
	}
	if (d > 9)
	{
		ft_putnbr(d / 10);
		ft_putnbr(d % 10);
	}
}

void	receive_msg(int signal)
{
	static int	byte;
	static int	n;

	if (signal == SIGUSR1)
	{
		byte = byte + (1 << (7 - n));
	}
	if (signal == SIGUSR2)
	{
		byte = byte + (0 << (7 - n));
	}
	n++;
	if (n == 8)
	{
		write(1, &byte, 1);
		n = 0;
		byte = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	write(1, "my pid is : ", 12);
	ft_putnbr(pid);
	write (1, "\n", 1);
	signal(SIGUSR1, receive_msg);
	signal(SIGUSR2, receive_msg);
	while (1)
		pause();
}
