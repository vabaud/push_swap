/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:39:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/27 21:40:29 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_a(t_stack **stack_a)
{
    t_stack *temp;

    temp = *stack_a;
    while (temp->next->next != NULL)
        temp = temp->next;
    stack_add_back(stack_a, ft_stacknew(temp->next->value));
    temp->next = NULL;
    printf("rra\n");
}

void reverse_rotate_b(t_stack **stack_b)
{
    t_stack *temp;

    temp = *stack_b;
    while (temp->next->next != NULL)
        temp = temp->next;
    stack_add_back(stack_b, ft_stacknew(temp->next->value));
    temp->next = NULL;
    printf("rrb\n");
}

void reverse_rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
    printf("rrr\n");
}
