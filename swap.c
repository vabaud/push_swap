/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:44:25 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/27 21:33:07 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack **stack_a)
{
    int tmp;
    tmp = (*stack_a)->value;
    (*stack_a)->value = (*stack_a)->next->value;
    (*stack_a)->next->value = tmp;
    printf("sa\n");
}

void swap_b(t_stack **stack_b)
{
    int tmp;
    tmp = (*stack_b)->value;
    (*stack_b)->value = (*stack_b)->next->value;
    (*stack_b)->next->value = tmp;
    printf("sb\n");
}

void swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    printf("ss\n");
}
