/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 22:17:18 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/10 16:44:05 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_isdigit(int n)
{
	if ((n >= 48 && n <= 57) || n == ' ' || n == '+' \
	|| n == '-' || (n >= '\t' && n <= '\r'))
	{
		return (1);
	}
	return (0);
}

int	is_number(int n, char **arg)
{
	int	i;

	while (n > 1)
	{
		i = 0;
		while (arg[n - 1][i] == ' ' \
		|| (arg[n - 1][i] >= '\t' && arg[n - 1][i] <= '\r'))
		{
			i++;
		}
		if (arg[n - 1][i] == '+' || arg[n - 1][i] == '-')
			i++;
		while (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 1)
			i++;
		if (arg[n - 1][i] && ft_isdigit(arg[n - 1][i]) == 0)
			return (0);
		n--;
	}
	return (1);
}

int	check_duplicate(t_stack *stack, int data)
{
	while (stack != NULL)
	{
		if (stack->data == data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

long	int	ft_atoi(const char *s, t_stack *top)
{
	long int	n;
	int			m;
	int			i;

	n = 0;
	m = 1;
	i = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
		i++;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			m *= -1;
	if (!s[i])
		exit_for_error(NULL, NULL);
	while (s[i] <= 57 && s[i] >= 48)
	{
		n = (n * 10) + (s[i++] - '0');
		if (((n * m) < -2147483648 || (n * m) > 2147483647))
			exit_for_error(&top, NULL);
	}
	if (s[i] != '\0')
		exit_for_error(&top, NULL);
	return (n * m);
}
