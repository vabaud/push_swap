/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:52:21 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 12:18:07 by vabaud           ###   ########.fr       */
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
    init_pos_and_cost(&stack_a);
    printf("%d\n", stack_size(&stack_a));
    while(stack_a != NULL)
    {
        printf("%d = %d\n",stack_a->pos, stack_a->cost);
        stack_a = stack_a->next;
    }
    (void)stack_b;
    return (0);
}
