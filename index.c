/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:25:28 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/17 19:48:17 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_node	*get_min(t_stack *stack)
{
	t_node	*tmp;
	t_node	*min;

	tmp = stack->top;
	min = NULL;
	while (tmp)
	{
		if (tmp->index == -1)
		{
			if (!min || tmp->value < min->value)
				min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	index_stack(t_stack *stack)
{
	t_node	*min;
	int		i;

	i = 0;
	while (i < stack->size)
	{
		min = get_min(stack);
		if (!min)
			return ;
		min->index = i;
		i++;
	}
}

void	set_positions(t_stack *stack)
{
	t_node	*tmp;
	int		i;
	int		median;

	i = 0;
	if (!stack || stack->size == 0)
		return ;
	tmp = stack->top;
	median = stack->size / 2;
	while (tmp)
	{
		tmp->pos = i;
		if (i <= median)
			tmp->above_median = true;
		else
			tmp->above_median = false;
		tmp = tmp->next;
		i++;
	}
}
