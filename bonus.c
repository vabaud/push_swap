/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 12:50:02 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/21 09:22:35 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (line[1] == 'a')
        swap(stack_a);
    else if (line[1] == 'b')
        swap(stack_b);
    else if (line[1] == 's')
    {
        swap(stack_a);
        swap(stack_b);
    }
    
}

void rot_or_rev_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (line[1] == 'r' && line[2] == 'r')
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
    }
    else if (line[1] == 'r' && line[2] == 'a')
        reverse_rotate(stack_a);
    else if (line[1] == 'r' && line[2] == 'b')
        reverse_rotate(stack_b);
    else if (line[1] == 'r')
    {
        rotate(stack_a);
        rotate(stack_b);
    }
    else if (line[1] == 'a')
        rotate(stack_a);
    else if (line[1] == 'b')
        rotate(stack_b);
}

void push_op(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (line[1] == 'a')
        push(stack_a, stack_b, 'a');
    else if (line[1] == 'b')
        push(stack_a, stack_b, 'b');
}

void operation(char *line, t_stack **stack_a, t_stack **stack_b)
{
    if (line[0] == 's')
        swap_op(line, stack_a, stack_b);
    else if (line[0] == 'r')
        rot_or_rev_op(line, stack_a, stack_b);
    else if(line[0] == 'p')
        push_op(line, stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	if (ac < 2)
		return 0;
	if (ac == 2)
		av = ft_split(av[1], ' ');
	args_check(ac, av);
	stack_a = init_stack(ac, av);
	stack_b = NULL;
    line = get_next_line(0);
	while (line)
	{
        operation(line, &stack_a, &stack_b);
        free(line);
        line = get_next_line(0);
	}
    if (is_sort(&stack_a))
        ft_printf("OK");
    else
        ft_printf("KO");
    free_stack(&stack_a);
    free_stack(&stack_b);
    return (0);
}
