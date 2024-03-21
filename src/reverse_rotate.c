/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:39:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 23:55:51 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*before_tail;

	tail = *stack;
	before_tail = *stack;
	while (tail->next)
		tail = tail->next;
	tmp = *stack;
	while (before_tail->next && before_tail->next->next)
		before_tail = before_tail->next;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	reverse_rotate_a(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_stack **stack)
{
	reverse_rotate(stack);
	ft_printf("rrb\n");
}

void	reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while ((*stack_a)->value != cheap->value
		&& (*stack_b)->value != cheap->target->value)
	{
		reverse_rotate_a_and_b(stack_a, stack_b);
	}
	init_pos(stack_a);
	init_pos(stack_b);
}
