/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:52:21 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 13:33:27 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		return (0);
    if (ac == 2)
    {
        av = ft_split(av[1], ' ');
    }
	args_check(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
	which_sort(&stack_a, &stack_b);
	return (0);
}
