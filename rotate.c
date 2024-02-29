/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:51:19 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 20:19:16 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate(t_stack **stack)
{
    t_stack *temp;

    temp = *stack;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = ft_stacknew((*stack)->value);
    temp->next->next = NULL;
    *stack = (*stack)->next;
}

void rotate_a(t_stack **stack)
{
    rotate(stack);
    printf("ra\n");
}

void rotate_b(t_stack **stack)
{
    rotate(stack);
    printf("rb\n");
}

void rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    rotate(stack_a);
    rotate(stack_b);
    printf("rr\n");
}
