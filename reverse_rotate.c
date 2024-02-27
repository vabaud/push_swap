/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:51:19 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/26 20:28:23 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(t_stack **stack_a)
{
    t_stack *temp;

    temp = *stack_a;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = ft_stacknew((*stack_a)->value);
    temp->next->next = NULL;
    *stack_a = (*stack_a)->next;
    printf("rra\n");
}

void reverse_rotate_b(t_stack **stack_b)
{
    t_stack *temp;

    temp = *stack_b;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = ft_stacknew((*stack_b)->value);
    temp->next->next = NULL;
    *stack_b = (*stack_b)->next;
    printf("rrb\n");
}

void reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
    printf("rrr\n");
}