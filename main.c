/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:52:21 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/29 16:11:16 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (ac < 2)
        return (0);
    args_check(av);
    stack_a = init_stack(ac, av);
    stack_b = NULL;
    printf("%d\n", stack_a->value);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    push_b(&stack_a, &stack_b);
    init_cost(&stack_a, &stack_b);
    while (stack_a)
    {
        printf("%d = %d\n", stack_a->value, stack_a->cost);
        stack_a = stack_a->next;
    }
    return (0);
}
