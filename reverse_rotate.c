/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:39:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 20:17:08 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while (temp->next->next != NULL)
        temp = temp->next;
    stack_add_back(stack, ft_stacknew(temp->next->value));
    temp->next = NULL;
}

void reverse_rotate_a(t_stack **stack)
{
    reverse_rotate(stack);
    printf("rra\n");
}

void reverse_rotate_b(t_stack **stack)
{
    reverse_rotate(stack);
    printf("rrb\n");
}

void reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    printf("rrr\n");
}
