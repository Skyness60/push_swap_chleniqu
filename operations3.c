/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:35:26 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 13:04:38 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack_node **a, t_stack_node **b, int j)
{
	ra(a, 1);
	rb(b, 1);
	if (j == 0)
		write(1, "rr\n", 3);
}

void	rrr(t_stack_node **a, t_stack_node **b, int j)
{
	rra(a, 1);
	rrb(b, 1);
	if (j == 0)
		write(1, "rrr\n", 4);
}

void	rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
		rr(a, b, 0);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(a, b, 0);
	current_index(*a);
	current_index(*b);
}
