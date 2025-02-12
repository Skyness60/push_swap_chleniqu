/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 12:06:53 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/07 12:06:58 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_number;

	biggest_number = find_max(*a);
	if (biggest_number == *a)//si notre biggest node est en haut de la pile, on le met en bat de la pile
		rotate_a(a, false);
	else if ((*a)->next == biggest_number)
		reverse_rotate_a(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		swap_a(a, false);
}