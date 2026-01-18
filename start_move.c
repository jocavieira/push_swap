/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:00:52 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/18 11:56:42 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	move_from_a_to_b(t_stack *stack_a, t_stack *stack_b, t_node *node)
{
	if (!node)
		return ;
	while (stack_a->top != node)
	{
		set_positions(stack_a);
		if (node->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
	while (stack_b->top != node->target && node->target)
	{
		set_positions(stack_b);
		if (node->target->above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	pb(stack_a, stack_b);
}

void	move_from_b_to_a(t_stack *stack_b, t_stack *stack_a, t_node *node)
{
	if (!node)
		return ;
	while (stack_b->top != node)
	{
		set_positions(stack_b);
		if (node->above_median)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while (stack_a->top != node->target && node->target)
	{
		set_positions(stack_a);
		if (node->target->above_median)
			ra(stack_a);
		else
			rra(stack_a);
	}
	pa(stack_b, stack_a);
}
