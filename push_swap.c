/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:26:04 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/13 17:28:23 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack stack_a;
    t_stack stack_b;

    if (argc < 2)
        return (0);
    init_stack(&stack_a);
    init_stack(&stack_b);
    parse_args(argc, argv, &stack_a);
    index_stack(&stack_a);
    if (!is_sorted(&stack_a))
    {
        if (stack_a.size <= 3)
            sort_small_stack(&stack_a);
        else
            turk_sort(&stack_a, &stack_b);
    }
    free_stack(&stack_a);
    if (stack_b.size > 0)
        free_stack(&stack_b);
    return (0);
}