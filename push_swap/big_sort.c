/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:06:37 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/03 19:25:07 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	largest_value(t_stack *stack)
{
	t_stack	*tmp;
	int		largest;

	tmp = stack;
	largest = 0;
	tmp = tmp->next;
	while (tmp)
	{
		if (largest < tmp->index)
			largest = tmp->index;
		tmp = tmp->next;
	}
	return (largest);
}

int	find_index_value(t_stack *stack_a, int value)
{
	int	index;

	index = 0;
	while (stack_a != NULL)
	{
		if (stack_a->data < value)
			index++;
		stack_a = stack_a->next;
	}
	return (index);
}

void	indexing(t_stack **stack_a)
{
	t_stack	*temp;

	temp = *stack_a;
	while (temp != NULL)
	{
		temp->index = find_index_value(*stack_a, temp->data);
		temp = temp->next;
	}	
}

int	no_of_bits(t_stack *stack_a)
{
	int	bits;
	int	large_value;

	bits = 0;
	large_value = put_position(stack_a);
	while ((large_value >> bits) != 0)
		bits++;
	return (bits);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	t_stack	*temp;
	int		bits;
	int		list_length;

	temp = *stack_a;
	bits = no_of_bits(temp);
	list_length = put_position(temp);
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j++ < list_length)
		{
			temp = *stack_a;
			if (((temp->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_b, stack_a);
		}
		while ((*stack_b) != NULL)
			pa(stack_a, stack_b);
		i++;
	}
}
