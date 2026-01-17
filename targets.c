/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:44:39 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 14:31:14 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *get_target_in_b(t_stack *stack_b, int index_a)
{
    t_node  *tmp;
    t_node  *target;

    tmp = stack_b->top;
    target = NULL;
    while (tmp)
    {
        if (tmp->index < index_a && (!target || tmp->index > target->index))
            target = tmp;
        tmp = tmp->next;
    }
    if (!target)
    {
        target = stack_b->top;
        tmp = target->next;
        while (tmp)
        {
            if (tmp->index > target->index)
                target = tmp;
            tmp = tmp->next;
        }
    }
    return (target);
}
void set_targets_a(t_stack *stack_a, t_stack *stack_b)
{
    t_node  *tmp;

    if (!stack_a || !stack_b)
        return ;
    tmp = stack_a->top;
    while (tmp)
    {
        tmp->target = get_target_in_b(stack_b, tmp->index);
        tmp = tmp->next;
    }
}
t_node *get_target_in_a(t_stack *stack_a, int index_b)
{
    t_node *tmp;
    t_node *target;

    tmp = stack_a->top;
    target = NULL;

    while (tmp)
    {
        if (tmp->index > index_b && (!target || tmp->index < target->index))
            target = tmp;
        tmp = tmp->next;
    }
    if (!target)
    {
        target = stack_a->top;
        tmp = target->next;
        while (tmp)
        {
            if (tmp->index < target->index)
                target = tmp;
            tmp = tmp->next;
        }
    }
    return (target);
}

void set_targets_b(t_stack *stack_b, t_stack *stack_a)
{
    t_node *tmp;

    if (!stack_a || !stack_b)
        return ;

    tmp = stack_b->top;
    while (tmp)
    {
        tmp->target = get_target_in_a(stack_a, tmp->index);
        tmp = tmp->next;
    }
}
