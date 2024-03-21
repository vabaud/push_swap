/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:32:58 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/21 12:32:23 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *stack;
	max = NULL;
	while (tmp)
	{
		if (max == NULL)
			max = tmp;
		else if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *stack;
	min = NULL;
	while (tmp)
	{
		if (min == NULL)
			min = tmp;
		else if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
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

int	is_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

t_stack	*cheapest(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	tmp = *stack;
	cheapest = NULL;
	while (tmp)
	{
		if (cheapest == NULL)
			cheapest = tmp;
		else if (tmp->cost < cheapest->cost)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}

void	init_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		if (i < (stack_size(stack) / 2))
			tmp->above_median = 1;
		else
			tmp->above_median = 0;
		i++;
		tmp = tmp->next;
	}
}

void	init_cost_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_a;
	init_pos(stack_a);
	init_pos(stack_b);
	while (tmp != NULL)
	{
		target_value_a(tmp, stack_b);
		tmp->cost = tmp->pos;
		if (tmp->pos > stack_size(stack_a) / 2)
			tmp->cost = stack_size(stack_a) - tmp->pos;
		if (!tmp->target->above_median)
			tmp->cost += stack_size(stack_b) - tmp->target->pos;
		else
			tmp->cost += tmp->target->pos;
		tmp = tmp->next;
	}
}

void	target_value_a(t_stack *stack, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = *stack_b;
	while (tmp != NULL)
	{
		if (stack->value > tmp->value)
		{
			if (stack->target == NULL)
				stack->target = tmp;
			else if (stack->target->value < tmp->value)
				stack->target = tmp;
		}
		tmp = tmp->next;
	}
	if (stack->target == NULL)
	{
		stack->target = max(stack_b);
	}
}

void	target_value_b(t_stack *stack, t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp != NULL)
	{
		if (stack->value < tmp->value)
		{
			if (stack->target == NULL)
				stack->target = tmp;
			else if (stack->target->value > tmp->value)
				stack->target = tmp;
		}
		tmp = tmp->next;
	}
	if (stack->target == NULL)
	{
		stack->target = min(stack_a);
	}
}

void	clear_near(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		tmp->target = NULL;
		tmp = tmp->next;
	}
}

void	min_on_top(t_stack **stack)
{
	init_pos(stack);
	while ((*stack)->value != min(stack)->value)
	{
		if (min(stack)->above_median)
			rotate_a(stack);
		else
			reverse_rotate_a(stack);
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*head;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
