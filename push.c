/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:53:15 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/29 13:48:01 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (*stack_a == NULL)
        return;
    tmp = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = tmp;
    printf("pb\n");
}
void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp;
    
    if (*stack_b == NULL)
        return;
    tmp = (*stack_b)->next;
    (*stack_b)->next = *stack_a;
    *stack_a = *stack_b;
    *stack_b = tmp;
    printf("pa\n");
}
