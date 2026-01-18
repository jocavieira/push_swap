/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 10:38:54 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/18 15:30:35 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static bool	check_duplicates(t_stack *stack, int value)
{
	t_node	*tmp;

	tmp = stack->top;
	while (tmp)
	{
		if (tmp->value == value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	is_sorted(t_stack *stack)
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

static bool	is_valid(t_stack *stack_a, char *str)
{
	long	tmp;
	int		value;

	if (!ft_is_number(str))
		return (false);
	if (ft_strlen(str) > 11)
		return (false);
	tmp = ft_atol(str);
	if (tmp > MAX || tmp < MIN)
		return (false);
	value = (int)tmp;
	if (!check_duplicates(stack_a, value))
		return (false);
	add_bottom(stack_a, new_node(value));
	return (true);
}

void	parse_args(int argc, char **argv, t_stack *stack_a)
{
	char	**split_args;
	int		i;
	int		j;

	i = 1;
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
			if (!is_valid(stack_a, split_args[j]))
			{
				free_split(split_args);
				error_exit(stack_a);
			}
			j++;
		}
		free_split(split_args);
		i++;
	}
}
