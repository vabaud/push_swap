/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 19:30:44 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/26 17:28:52 by vabaud           ###   ########.fr       */
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
	new->next = NULL;
	return (new);
}

void stack_add_front(t_stack **stack, t_stack *new)
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

t_stack *init_stack(int ac, char **av)
{
    int i;
    t_stack *stack;

    i = 1;
    while (i < ac)
    {
        if (i == 1)
            stack = ft_stacknew(ft_atoi(av[i]));
        else
            stack_add_front(&stack, ft_stacknew(ft_atoi(av[i])));
        i++;
    }
    return (stack);
}