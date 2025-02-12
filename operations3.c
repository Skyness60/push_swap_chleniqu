/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:35:26 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/10 11:35:31 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rr(t_stack_node **a, t_stack_node **b, int j)
{
    ra(a, 1);
    rb(b, 1);
    if (j == 0)
        write(1, "rr\n", 3);
}

void    rrr(t_stack_node **a, t_stack_node **b, int j)
{
    rra(a, 1);
    rrb(b, 1);
    if (j == 0)
        write(1, "rrr\n", 4);
}

/**
 * - BOnjour je suis toot
 * @param **a: c'est la stack A
 * @param **b: c'est la stack B
 * @return rien
**/

static void rotate_both(t_stack_node **a,
						t_stack_node **b,
						t_stack_node *cheapest_node)
{
    while (*b != cheapest_node && *a != cheapest_node)//arrêt lorsque les deux nœuds sont en haut de leurs piles
//Si *b == target_node : Le target_node est en haut de b. On n'a plus besoin de faire des rotations sur b.
//Si *a == cheapest_node : Le cheapest_node est en haut de a. On n'a plus besoin de faire des rotations sur a.
        rr(*a, *b, 0);
    current_index(*a);
    current_index(*b);
//Après les rotations, la position des nœuds dans les piles a changé, on met à jour les index
}

static void	reverse_rotate_both(t_stack_node **a,
								t_stack_node **b,
								t_stack_node *cheapest_node)
{
	while(*b != cheapest_node->target_node && *a != cheapest_node)
		rrr(*a, *b, 0);
	current_index(*a);
	current_index(*b);
}
