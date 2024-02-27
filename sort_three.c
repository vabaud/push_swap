/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:35:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/27 14:28:10 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack **stack)
{
    t_stack *top;
    t_stack *middle;

    top = (*stack)->next->next;
    middle = (*stack)->next;
    if ((*stack)->value < middle->value && middle->value > top->value && top->value < (*stack)->value)
    {
        swap_a(stack);
        rotate_a(stack);
    }
    else if ((*stack)->value < middle->value && middle->value < top->value)
    {
        swap_a(stack);
        reverse_rotate_a(stack);
    }
    else if (middle->value < top->value && (*stack)->value > top->value)
        swap_a(stack);
    else if (middle->value > top->value && (*stack)->value < top->value)
        reverse_rotate_a(stack);
    else if (middle->value < top->value && (*stack)->value < top->value)
        rotate_a(stack);
}
