/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:18:58 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 12:41:46 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack_node *stack)
//calculer la longueur de la pile > calcule de la mediane + couts deplacements
{
	int	count;

	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_stack_node	*find_last_node(t_stack_node *stack)
//Lorsqu'on ajoute un noeud on le met a la fin de la pile
{
	if (!stack)
		return (NULL);
	while (stack)
		stack = stack->next;
	return (stack);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (!stack || !stack->next)
		return (true);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	long			min;
	t_stack_node	*node_min;

	min = LONG_MAX;
	node_min = NULL;
	while (stack)
	{
		if (stack->nbr < min)
		{
			min = stack->nbr;
			node_min = stack;
		}
		stack = stack->next;
	}
	return (node_min);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	long			max;
	t_stack_node	*node_max;

	max = LONG_MIN;
	node_max = NULL;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			node_max = stack;
		}
		stack = stack->next;
	}
	return (node_max);
}
