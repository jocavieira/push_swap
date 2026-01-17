/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:55:33 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 09:40:17 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
    t_node *tmp;

    if (!stack_a || !stack_b)
        return ;
    tmp = stack_a->top;
    while (tmp)
    {
        if (tmp->above_median)
            tmp->cost_a = tmp->pos;
        else
            tmp->cost_a = stack_a->size - tmp->pos;
        if (tmp->target->above_median)
            tmp->cost_b = tmp->target->pos;
        else
            tmp->cost_b = stack_b->size - tmp->target->pos;

        tmp = tmp->next;
    }
}
t_node *find_cheapest_move(t_stack *stack_a)
{
    t_node  *tmp;
    t_node  *cheapest;
    int     min;
    int     total;

    if (!stack_a || stack_a->size == 0)
        return (NULL);
    tmp = stack_a->top;
    cheapest = tmp;
    min = tmp->cost_a + tmp->cost_b;
    tmp = tmp->next;
    while (tmp)
    {
        total = tmp->cost_a + tmp->cost_b;
        if (total < min)
        {
            min = total;
            cheapest = tmp;
        }
        tmp = tmp->next;
    }
    return (cheapest);
}
