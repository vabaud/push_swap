/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:35:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/19 19:08:36 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*bottom;
	t_stack	*middle;

	bottom = (*stack)->next->next;
	middle = (*stack)->next;
	if ((*stack)->value < middle->value && middle->value > bottom->value
		&& bottom->value > (*stack)->value)
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if ((*stack)->value > middle->value && middle->value > bottom->value)
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (middle->value < bottom->value && (*stack)->value < bottom->value)
		swap_a(stack);
	else if (middle->value > bottom->value && (*stack)->value < middle->value)
		reverse_rotate_a(stack);
	else if (middle->value < bottom->value && (*stack)->value > bottom->value)
		rotate_a(stack);
}
