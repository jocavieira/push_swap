/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:11:21 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 10:11:26 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void reverse_rotate(t_stack *stack)
{
    t_node *last;

    if (!stack || stack->size < 2)
        return ;
    last = stack->bottom;
    stack->bottom = last->prev;
    stack->bottom->next = NULL;
    last->prev = NULL;
    last->next = stack->top;
    stack->top->prev = last;
    stack->top = last;
}

void rra(t_stack *stack_a)
{
    reverse_rotate(stack_a);
    write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b)
{
    reverse_rotate(stack_b);
    write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    reverse_rotate(stack_a);
    reverse_rotate(stack_b);
    write(1, "rrr\n", 4);
}