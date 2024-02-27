/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 19:44:25 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/26 20:26:01 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_a(t_stack **stack_a)
{
    int tmp;
    t_stack *stemp;

    stemp = *stack_a;
    while(stemp->next->next != NULL)
        stemp = stemp->next;
    tmp = stemp->value;
    stemp->value = stemp->next->value;
    stemp->next->value = tmp;
    printf("sa\n");
}

void swap_b(t_stack **stack_b)
{
    int tmp;
    t_stack *stemp;

    stemp = *stack_b;
    while(stemp->next->next != NULL)
        stemp = stemp->next;
    tmp = stemp->value;
    stemp->value = stemp->next->value;
    stemp->next->value = tmp;
    printf("sb\n");
}

void swap_a_and_b(t_stack **stack_a, t_stack **stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
    printf("ss\n");
}
