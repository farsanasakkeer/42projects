/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:25:40 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/15 19:02:57 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		else
			return (0);
	}
	return (result);
}

void	send_msg(char msg, int pid)
{
	int	i;
	int	j;

	i = 7;
	while (i >= 0)
	{
		if (msg >> i & 1)
			j = kill (pid, SIGUSR1);
		else
			j = kill (pid, SIGUSR2);
		if (j == -1)
		{
			write (1, "kill function failed\n", 21);
			exit(1);
		}
		i--;
		usleep(250);
	}
}

int	main(int n, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (n == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			write (1, "invalid pid\n", 12);
			return (0);
		}
		while (argv[2][i])
		{
			send_msg(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		write (1, "Arguments error\n", 16);
		exit(1);
	}
}
