/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 08:39:10 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/26 19:23:57 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a(t_stack **stack_a)
{
    t_stack *temp;

    temp = *stack_a;
    while (temp->next->next != NULL)
        temp = temp->next;
    stack_add_front(stack_a, ft_stacknew(temp->next->value));
    temp->next = NULL;
    printf("ra\n");
}

void rotate_b(t_stack **stack_b)
{
    t_stack *temp;

    temp = *stack_b;
    while (temp->next->next != NULL)
        temp = temp->next;
    stack_add_front(stack_b, ft_stacknew(temp->next->value));
    temp->next = NULL;
    printf("rb\n");
}

void rotate_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    rotate_a(stack_a);
    rotate_b(stack_b);
    printf("rr\n");
}