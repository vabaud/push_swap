/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vabaud <vabaud@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:55:00 by vabaud            #+#    #+#             */
/*   Updated: 2024/03/21 10:01:46 by vabaud           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && str[i] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ft_atoi(str) > INT_MAX || ft_atoi(str) < INT_MIN)
	{
		return (0);
	}
	return (1);
}

int	is_dup(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 1;
		while (str[j])
		{
			if (j != i && (ft_atoi(str[i]) == ft_atoi(str[j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	args_check(int ac, char **av)
{
	int	i;

	i = 1;
    if (ac == 2)
    {
        i = 0;
    }
	while (av[i])
	{
		if (!is_num(av[i]))
        {
            ft_printf("Error\n");
			exit(EXIT_FAILURE);
        }
		i++;
	}
	if (!is_dup(av))
    {
        ft_printf("Error\n");
		exit(EXIT_FAILURE);
    }
}
