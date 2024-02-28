/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:44:41 by vabaud            #+#    #+#             */
/*   Updated: 2024/02/28 12:17:47 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "LIBFT/libft.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				pos;
    int cost;
	struct s_stack	*next;
}					t_stack;

int					main(int ac, char **av);

void				rotate_a(t_stack **stack_a);
void				rotate_b(t_stack **stack_b);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate_a(t_stack **stack_a);
void				reverse_rotate_b(t_stack **stack_a);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);

void				swap_a(t_stack **stack_a);
void				swap_b(t_stack **stack_b);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);

void				sort_three(t_stack **stack);

int					is_num(char *str);
int					is_dup(char **str);
void				args_check(char **av);
t_stack				*ft_stacknew(int content);
void				stack_add_front(t_stack **stack, t_stack *new);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*init_stack(int ac, char **av);
int					stack_size(t_stack **stack);
void				init_pos_and_cost(t_stack **stack);

#endif