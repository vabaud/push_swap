/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 10:44:41 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/20 12:55:02 by vabaud           ###   ########.fr       */
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
	int				cost;
	int				above_median;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

int					main(int ac, char **av);

void				rotate(t_stack **stack);
void				rotate_a(t_stack **stack);
void				rotate_b(t_stack **stack);
void				rotate_a_and_b(t_stack **stack_a, t_stack **stack_b);

void				reverse_rotate(t_stack **stack);
void				reverse_rotate_a(t_stack **stack);
void				reverse_rotate_b(t_stack **stack);
void				reverse_rotate_a_and_b(t_stack **stack_a,
						t_stack **stack_b);

void				swap(t_stack **stack);
void				swap_a(t_stack **stack);
void				swap_b(t_stack **stack);
void				swap_a_and_b(t_stack **stack_a, t_stack **stack_b);

void				push_a(t_stack **stack_a, t_stack **stack_b);
void				push_b(t_stack **stack_a, t_stack **stack_b);

void				sort_three(t_stack **stack);

int					is_num(char *str);
int					is_dup(char **str);
void				args_check(int ac, char **av);

t_stack				*ft_stacknew(int content);
void				stack_add_front(t_stack **stack, t_stack *new);
void				stack_add_back(t_stack **stack, t_stack *new);
t_stack				*init_stack(int ac, char **av);
int					stack_size(t_stack **stack);
void				init_cost_a(t_stack **stack_a, t_stack **stack_b);
void				init_cost_b(t_stack **stack_a, t_stack **stack_b);
void				target_value_a(t_stack *stack, t_stack **stack_b);
void				target_value_b(t_stack *stack, t_stack **stack_a);
t_stack				*max(t_stack **stack);
t_stack				*min(t_stack **stack);
t_stack				*cheapest(t_stack **stack);
int					is_sort(t_stack **stack);
void				which_sort(t_stack **stack_a, t_stack **stack_b);
void				sort(t_stack **stack_a, t_stack **stack_b);
void				go_top(t_stack **stack_a, t_stack *cheap, char stack_name);
void				move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void				move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void				init_pos(t_stack **stack_a);
void				do_rrr(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheap);
void				do_rr(t_stack **stack_a, t_stack **stack_b, t_stack *cheap);
void				clear_near(t_stack **stack);
void				min_on_top(t_stack **stack);
void checker(int ac, char **av);

#endif