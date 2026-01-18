/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarlo2 <jocarlo2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:08:23 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/18 13:51:35 by jocarlo2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack *stack)
{
	if (stack)
		free_stack(stack);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i])
	{
		free(split_args[i]);
		i++;
	}
	free(split_args);
	split_args = NULL;
}

void	free_stack(t_stack *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack->top)
	{
		tmp = stack->top;
		stack->top = stack->top->next;
		free(tmp);
	}
	stack->bottom = NULL;
	stack->size = 0;
}
