/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 10:09:10 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/17 19:50:32 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dst)
{
	t_node	*tmp;

	if (!src || src->size == 0)
		return ;
	tmp = src->top;
	src->top = tmp->next;
	if (src->top)
		src->top->prev = NULL;
	else
		src->bottom = NULL;
	tmp->next = dst->top;
	tmp->prev = NULL;
	if (dst->top)
		dst->top->prev = tmp;
	else
		dst->bottom = tmp;
	dst->top = tmp;
	src->size--;
	dst->size++;
}

void	pa(t_stack *src, t_stack *dst)
{
	push(src, dst);
	write(1, "pa\n", 3);
}

void	pb(t_stack *src, t_stack *dst)
{
	push(src, dst);
	write(1, "pb\n", 3);
}
