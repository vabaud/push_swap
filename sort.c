/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 16:35:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 12:04:36 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	which_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) == 2 && !is_sort(stack_a))
		swap_a(stack_a);
	else if (stack_size(stack_a) == 3 && !is_sort(stack_a))
		sort_three(stack_a);
	else if (stack_size(stack_a) > 3 && !is_sort(stack_a))
		sort(stack_a, stack_b);
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_size(stack_a) > 3 && !is_sort(stack_a))
		push_b(stack_a, stack_b);
	if (stack_size(stack_a) > 3 && !is_sort(stack_a))
		push_b(stack_a, stack_b);
	while (stack_size(stack_a) > 3 && !is_sort(stack_a))
	{
		init_pos(stack_a);
		init_pos(stack_b);
		move_a_to_b(stack_a, stack_b);
		clear_near(stack_a);
	}
	sort_three(stack_a);
	while (*stack_b)
	{
		init_pos(stack_a);
		init_pos(stack_b);
		clear_near(stack_b);
		target_value_b(*stack_b, stack_a);
		move_b_to_a(stack_a, stack_b);
		clear_near(stack_b);
	}
	min_on_top(stack_a);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheap;

	init_cost_a(stack_a, stack_b);
	cheap = cheapest(stack_a);
	if (cheap->above_median && cheap->target->above_median)
		do_rr(stack_a, stack_b, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		do_rrr(stack_a, stack_b, cheap);
	go_top(stack_a, cheap, 'a');
	go_top(stack_b, cheap->target, 'b');
	push_b(stack_a, stack_b);
}

void	go_top(t_stack **stack, t_stack *cheap, char stack_name)
{
	while ((*stack)->value != cheap->value)
	{
		if (stack_name == 'a')
		{
			if (cheap->above_median)
				rotate_a(stack);
			else
				reverse_rotate_a(stack);
		}
		else if (stack_name == 'b')
		{
			if (cheap->above_median)
				rotate_b(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	go_top(stack_a, (*stack_b)->target, 'a');
	push_a(stack_a, stack_b);
}
