/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:05:24 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 10:05:26 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void swap(t_stack *stack)
{
    t_node *first;
    t_node *second;

    if (!stack || stack->size < 2)
        return ;
    first = stack->top;
    second = first->next;
    first->next = second->next;
    if (second->next)
        second->next->prev = first;
    second->prev = NULL;
    second->next = first;
    first->prev = second;
    stack->top = second;
    if (stack->size == 2)
        stack->bottom = first;
}

void sa(t_stack *stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}

void sb(t_stack *stack_b)
{
    swap(stack_b);
    write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    swap(stack_a);
    swap(stack_b);
    write(1, "ss\n", 3);
}