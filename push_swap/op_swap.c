/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:32:04 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/27 17:30:06 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_fn(t_stack *top)
{
	int	temp;

	if (!top || top->next == NULL)
		return ;
	temp = top->data;
	top->data = top->next->data;
	top->next->data = temp;
}

void	sa(t_stack *top)
{
	swap_fn(top);
	write(1, "sa\n", 3);
}

void	sb(t_stack *list)
{
	swap_fn(list);
	write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	write(1, "ss\n", 3);
}
