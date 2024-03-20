/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:30:44 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 11:22:01 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = content;
	new->pos = 0;
	new->cost = 0;
	new->above_median = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

void	stack_add_front(t_stack **stack, t_stack *new)
{
	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	*stack = new;
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!*stack)
		*stack = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_stack	*init_stack(int ac, char **av)
{
	int		i;
	t_stack	*stack;

	i = 1;
    if (ac == 2)
        i = 0;
    else
    {
        stack = ft_stacknew(ft_atoi(av[i]));
        i = 2;
    }
	while (av[i])
	{
		if (i == 0)
			stack = ft_stacknew(ft_atoi(av[i]));
		else
			stack_add_back(&stack, ft_stacknew(ft_atoi(av[i])));
		i++;
	}
	return (stack);
}
