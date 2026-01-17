/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:25:00 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 12:51:32 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_node *new_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node->value = value;
    node->index = -1;
    node->pos = -1;
    node->target = NULL;
    node->cost_a = 0;
    node->cost_b = 0;
    node->above_median = false;
    node->prev = NULL;
    node->next = NULL;
    return (node);
}

void init_stack(t_stack *stack)
{
    stack->top = NULL;
    stack->bottom = NULL;
    stack->size = 0;
}

void add_bottom(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return ;
    if (stack->size == 0)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        node->prev = stack->bottom;
        stack->bottom->next = node;
        stack->bottom = node;
    }
    stack->size++;
}

void add_top(t_stack *stack, t_node *node)
{
    if (!stack || !node)
        return ;
    if (stack->size == 0)
    {
        stack->top = node;
        stack->bottom = node;
    }
    else
    {
        node->next = stack->top;
        stack->top->prev = node;
        stack->top = node;
    }
    stack->size++;
}

void free_stack(t_stack *stack)
{
    t_node *tmp;

    while (stack->top)
    {
        tmp = stack->top;
        stack->top = stack->top->next;
        free(tmp);
    }
    stack->bottom = NULL;
    stack->size = 0;
}