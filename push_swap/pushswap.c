/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:33:42 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/03/10 16:43:09 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	elements;

	elements = put_position(*stack_a);
	if (elements == 1)
		exit_for_error(stack_a, NULL);
	if (elements == 2)
		sa(*stack_a);
	else if (elements == 3)
		three_element_sort(stack_a);
	else if (elements == 4)
		four_element_sort(stack_a, stack_b);
	else if (elements == 5)
		five_element_sort(stack_a, stack_b);
	else
	{
		indexing(stack_a);
		big_sort(stack_a, stack_b);
	}
}

int	main(int argn, char **argc)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	if (argn < 2)
		return (0);
	flag = is_number(argn, argc);
	if (flag == 0)
		exit_for_error(NULL, NULL);
	stack_b = NULL;
	stack_a = convert_to_lst(argn, argc);
	if ((is_sorted(stack_a)) == 0)
		push_swap(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
