/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:32:58 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/29 16:11:02 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *max(t_stack **stack)
{
    t_stack *tmp;
    t_stack *max;

    tmp = *stack;
    max = *stack;
    while (tmp)
    {
        if (tmp->value >= max->value)
            max = tmp;
        tmp = tmp->next;
    }
    return max;
}

int	stack_size(t_stack **stack)
{
	t_stack	*tmp;
	int		len;

	tmp = *stack;
	len = 0;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

void    init_pos(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *tmp_a;
    t_stack *tmp_b;
    int i;

    tmp_a = *stack_a;
    tmp_b = *stack_b;
    i = 0;
    while (tmp_a)
    {
        tmp_a->pos = i;
        i++;
        tmp_a = tmp_a->next;
    }
    i = 0;
    while (tmp_b)
    {
        tmp_b->pos = i;
        i++;
        tmp_b = tmp_b->next;
    }

}

void	init_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_a;
	i = 0;
    init_pos(stack_a, stack_b);
	while (tmp != NULL)
	{
        near_value(tmp, stack_b);
		tmp->cost = i;
        if (i > stack_size(stack_a) / 2)
            tmp->cost = stack_size(stack_a) - i;
        if (tmp->target->pos > stack_size(stack_b) / 2)
            tmp->cost += stack_size(stack_b) - tmp->target->pos;
        else
            tmp->cost += tmp->target->pos;
		i++;
		tmp = tmp->next;
	}
}

void near_value(t_stack *stack, t_stack **stack_b)
{
    t_stack *tmp;

    tmp = *stack_b;
    while(tmp != NULL)
    {
        if (stack->value > tmp->value)
        {
            if (stack->target == NULL)
                stack->target = tmp;
            else if (stack->target->value < tmp->value)
                stack->target = tmp;
        }
        else if(stack->target == NULL)
            stack->target = max(stack_b);
        tmp = tmp->next;
    }
}
