/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:53:15 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/27 15:15:07 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

    if (*stack_a == NULL)
        return;
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while(tmp_a->next != NULL)
        tmp_a = tmp_a->next;
    if(tmp_b == NULL)
        *stack_b = ft_stacknew(tmp_a->value);
    else
    {
        while(tmp_b->next != NULL)
            tmp_b = tmp_b->next;
        tmp_b->next = ft_stacknew(tmp_a->value);
    }
    tmp_a = NULL;
    printf("pb\n");
}
void push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;

    if (*stack_b == NULL)
        return;
    tmp_a = *stack_a;
    tmp_b = *stack_b;
    while(tmp_b->next != NULL)
        tmp_b = tmp_b->next;
    if(tmp_b == NULL)
        *stack_a = ft_stacknew(tmp_b->value);
    else
    {
        while(tmp_a->next != NULL)
            tmp_a = tmp_a->next;
        tmp_a->next = ft_stacknew(tmp_b->value);
    }
    tmp_b = NULL;
    printf("pa\n");
}
