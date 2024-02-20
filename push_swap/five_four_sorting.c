/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_four_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 21:03:55 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/27 19:33:26 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	four_element_sort(t_stack **stack_a, t_stack **stack_b)
{
	put_position(*stack_a);
	if (low_value_pos(*stack_a) == 1 || large_value_pos(*stack_a) == 1)
	{
		pb(stack_b, stack_a);
		three_element_sort(stack_a);
		pa(stack_a, stack_b);
		if (is_sorted(*stack_a) == 0)
			ra(stack_a);
	}
	else if (low_value_pos(*stack_a) == 4 || large_value_pos(*stack_a) == 4)
	{
		rra(stack_a);
		if (is_sorted(*stack_a) == 0)
			four_element_sort(stack_a, stack_b);
	}
	else
	{
		sa(*stack_a);
		four_element_sort(stack_a, stack_b);
	}
	put_position(*stack_a);
}

void	five_element_sort(t_stack **stack_a, t_stack **stack_b)
{
	put_position(*stack_a);
	if (low_value_pos(*stack_a) == 1 || large_value_pos(*stack_a) == 1)
	{
		pb(stack_b, stack_a);
		if (is_sorted(*stack_a) == 0)
			four_element_sort(stack_a, stack_b);
		pa(stack_a, stack_b);
		if (is_sorted(*stack_a) == 0)
			ra(stack_a);
	}
	else if (low_value_pos(*stack_a) == 5 || large_value_pos(*stack_a) == 5)
	{
		rra(stack_a);
		five_element_sort(stack_a, stack_b);
	}
	else if (low_value_pos(*stack_a) == 4 || large_value_pos(*stack_a) == 4)
	{
		rra(stack_a);
		five_element_sort(stack_a, stack_b);
	}
	else if (low_value_pos(*stack_a) == 2 || large_value_pos(*stack_a) == 2)
	{
		sa(*stack_a);
		five_element_sort(stack_a, stack_b);
	}
}
