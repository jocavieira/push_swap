/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:08:52 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/18 11:46:37 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define MAX 2147483647
# define MIN -2147483648

typedef struct s_node
{
	int				value;
	int				index;
	int				pos;
	struct s_node	*target;
	int				cost_a;
	int				cost_b;
	bool			above_median;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	t_node			*bottom;
	int				size;
}					t_stack;
// error handling and frees
void				error_exit(t_stack *stack);
void				free_split(char **split_args);
// parse functions
long				ft_atol(char *str);
bool				ft_is_number(char *str);
//void				check_duplicates(t_stack *stack, int value);
bool				is_sorted(t_stack *stack);
void				parse_args(int argc, char **argv, t_stack *stack_a);
char				**ft_split(char const *s, char c);
// stack and node functions
t_node				*new_node(int value);
void				init_stack(t_stack *stack);
void				add_bottom(t_stack *stack, t_node *node);
void				free_stack(t_stack *stack);
// indexing and positioning functions
void				index_stack(t_stack *stack);
void				set_positions(t_stack *stack);

// target and cost functions
void				set_targets_a(t_stack *stack_a, t_stack *stack_b);
void				set_targets_b(t_stack *stack_b, t_stack *stack_a);
t_node				*get_target_in_b(t_stack *stack_b, int index_a);
t_node				*get_target_in_a(t_stack *stack_a, int index_b);
void				calculate_costs(t_stack *stack_a, t_stack *stack_b);
t_node				*find_cheapest_move(t_stack *stack_a);
// move functions
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_a, t_stack *stack_b);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void				move_from_a_to_b(t_stack *src, t_stack *dst, t_node *node);
void				move_from_b_to_a(t_stack *src, t_stack *dst, t_node *node);
// sorting functions
void				turk_sort(t_stack *stack_a, t_stack *stack_b);
void				rotate_to_min(t_stack *stack);
void				sort_small_stack(t_stack *stack);

#endif