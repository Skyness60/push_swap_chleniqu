/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:15:13 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 12:48:24 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_target_b(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*current_node;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		current_node = a;
		best_match_index = LONG_MAX;
		while (current_node)
		{
			if (current_node->nbr > b->nbr
				&& current_node->nbr < best_match_index)
			{
				best_match_index = current_node->nbr;
				target_node = current_node;
			}
			current_node = current_node->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	init_node_b(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_b(b, a);
}
