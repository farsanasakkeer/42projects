/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 20:30:54 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/10 09:59:42 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	large_value_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		large;
	int		pos;

	tmp = stack;
	large = tmp->data;
	pos = tmp->position;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (large < tmp->data)
		{
			large = tmp->data;
			pos = tmp->position;
		}
	}
	return (pos);
}

int	low_value_pos(t_stack *stack)
{
	t_stack	*tmp;
	int		low;
	int		pos;

	tmp = stack;
	low = tmp->data;
	pos = tmp->position;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (low > tmp->data)
		{
			low = tmp->data;
			pos = tmp->position;
		}
	}
	return (pos);
}

int	put_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 1;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
	return (i - 1);
}

void	three_element_sort(t_stack **stack_a)
{
	if (is_sorted(*stack_a) == 1)
		return ;
	put_position(*stack_a);
	if (large_value_pos(*stack_a) == 3)
	{
		sa(*stack_a);
	}
	else if (large_value_pos(*stack_a) == 1)
	{
		ra(stack_a);
		if ((is_sorted(*stack_a)) == 0)
			sa(*stack_a);
	}
	else if (low_value_pos(*stack_a) == 3)
	{
		rra(stack_a);
	}
	else
	{
		sa(*stack_a);
		ra(stack_a);
	}
}
