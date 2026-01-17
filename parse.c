/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:38:54 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/17 15:31:50 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void check_duplicates(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			error_exit(stack);
		tmp = tmp->next;
	}
}
bool is_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return (true);
	tmp = stack->top;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static void	is_valid(t_stack *stack_a, char *str)
{
	long	tmp;
	int		value;

	if (!ft_is_number(str))
		error_exit(stack_a);
	tmp = ft_atol(str);
	if (tmp > MAX || tmp < MIN)
		error_exit(stack_a);
	value = (int)tmp;
	check_duplicates(stack_a, value);
	add_bottom(stack_a, new_node(value));
}


void	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**split_args;
	int		i;
	int		j;

	i = 1;
	init_stack(stack_a);
	while (i < argc)
	{
		if (!argv[i] || argv[i][0] == '\0')
			error_exit(stack_a);
		split_args = ft_split(argv[i], ' ');
		if (!split_args)
			error_exit(stack_a);
		j = 0;
		while (split_args[j])
		{
			is_valid(stack_a, split_args[j]);
			j++;
		}
		free_split(split_args);
		i++;
	}
}
