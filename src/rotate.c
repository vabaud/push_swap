/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:51:19 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 23:55:54 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	tail = *stack;
	*stack = (*stack)->next;
	while (tail && tail->next != NULL)
		tail = tail->next;
	tmp->next = NULL;
	tail->next = tmp;
}

void	rotate_a(t_stack **stack)
{
	rotate(stack);
	ft_printf("ra\n");
}

void	rotate_b(t_stack **stack)
{
	rotate(stack);
	ft_printf("rb\n");
}

void	rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while ((*stack_b)->value != cheap->target->value
		&& (*stack_a)->value != cheap->value)
		rotate_a_and_b(stack_a, stack_b);
	init_pos(stack_a);
	init_pos(stack_b);
}
