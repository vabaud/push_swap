/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:44:25 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 20:20:24 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_stack **stack)
{
    int tmp;
    tmp = (*stack)->value;
    (*stack)->value = (*stack)->next->value;
    (*stack)->next->value = tmp;
    printf("sa\n");
}

void swap_a(t_stack **stack)
{
    swap(stack);
    printf("sa\n");
}

void swap_b(t_stack **stack)
{
    swap(stack);
    printf("sb\n");
}

void swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    swap(stack_a);
    swap(stack_b);
    printf("ss\n");
}
