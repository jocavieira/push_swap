/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:07:06 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 17:28:07 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	turk_sort(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*cheapest;

	while (stack_a->size > 3 && stack_b->size < 2)
		pb(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		set_targets_a(stack_a, stack_b);
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest_move(stack_a);
		move_from_a_to_b(stack_a, stack_b, cheapest);
	}
	sort_small_stack(stack_a);
	while (stack_b->size > 0)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		set_targets_b(stack_b, stack_a);
		calculate_costs(stack_b, stack_a);
		cheapest = find_cheapest_move(stack_b);
		move_from_b_to_a(stack_b, stack_a, cheapest);
	}
	set_positions(stack_a);
	rotate_to_min(stack_a);
}

void	rotate_to_min(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || stack->size < 2)
		return ;
	tmp = stack->top;
	while (tmp->index != 0)
		tmp = tmp->next;
	while (stack->top->index != 0)
	{
		if (tmp->above_median)
			ra(stack);
		else
			rra(stack);
	}
}

static int	find_highest(t_stack *stack)
{
	int		index;
	t_node	*tmp;

	if (!stack || !stack->top)
		return (0);
	tmp = stack->top;
	index = tmp->index;
	while (tmp)
	{
		if (tmp->index > index)
			index = tmp->index;
		tmp = tmp->next;
	}
	return (index);
}

void	sort_small_stack(t_stack *stack)
{
	int	highest;

	if (!stack || stack->size < 2 || is_sorted(stack))
		return ;
	highest = find_highest(stack);
	if (stack->top->index == highest)
		ra(stack);
	else if (stack->top->next->index == highest)
		rra(stack);
	if (stack->top->index > stack->top->next->index)
		sa(stack);
}
