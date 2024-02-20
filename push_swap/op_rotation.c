/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 17:36:19 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/27 17:29:26 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	tail = *stack_b;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*tail;

	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	tail = *stack_a;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = temp;
	temp->next = NULL;
	write(1, "ra\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
