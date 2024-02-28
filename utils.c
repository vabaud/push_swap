/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 18:32:58 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 12:19:20 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	init_pos_and_cost(t_stack **stack)
{
	t_stack	*tmp;
	int		len;
	int		i;

	tmp = *stack;
	i = 0;
	len = stack_size(stack) / 2;
	while (tmp != NULL)
	{
		if (i > len && stack_size(stack) % 2 == 0)
		{
			len--;
			tmp->cost = len;
		}
		else if (i > len && stack_size(stack) % 2 != 0)
		{
			tmp->cost = len;
			len--;
		}
		else
			tmp->cost = i;
        tmp->pos = i + 1;
		i++;
		tmp = tmp->next;
	}
	i = 1;
}
