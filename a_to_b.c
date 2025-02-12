/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 12:32:31 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/05 12:32:35 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack_node *stack)
//determine si le noeud est en dessous ou au dessus de la mediane
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		++i;
	}
}

void	set_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_node;
	t_stack_node	*target_node;
	long			best_match_index;

	current_node = b;
	best_match_index = LONG_MIN;
	while (a)
	{
		while (current_node)
		{
			if (current_node->nbr > a->nbr
				&& current_node > best_match_index)//si notre nombre est plus petit et qu'il est plus grande que notre meilleure combinaison
			{
				best_match_index = current_node->nbr;
				target_node = current_node;
			}
			current_node = current_node->next;//on continue dans toute la liste pour essayer de trouver une meilleure combinaison
		}
		if (best_match_index == LONG_MIN)//si notre best match n'a pas change de notre valeur par defaut, on a pas trouve de nombre plus petit que a, c'est donc le plus petit
			a->target_node = find_max(b);//on cherche donc le maximum
		else
			a->target_node = target_node;//on associe notre target node a celui u'on a trouve
		a = a->next;//on passe au noeud suivant pour lui trouver son propre target node
	}
}

static void	cost_analysis(t_stack_node *a, t_stack_node *b)//calcule du nombre de deplacements pour que les target de a et b soient en haut de la pile
{
	int	len_a;//recuperation des longueurs de a et b pour calculer les rotations possible
	int	len_b;

	len_a = stack_len(a);
	len_b = stack_len(b);
	a->push_cost = a->index;
	while (a)
	{
		if (!(a->above_median))//si on est en dessous du milieu
			a->push_cost = len_a - (a->index);//longueur de la liste moins l'index
		if (a->target_node->above_median)//si notre target node est au dessus de la mediane
			a->push_cost += a->target_node->index;//son nombre d'operation est son index + l'index de son target node
		else//si notre target node est sous la mediane
			a->push_cost += len_b - (a->target_node->index);//longueur de otre liste moins l'index de notre target node
		a = a->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long			cheapest_value;
	t_stack_node	*cheapest_node;

	cheapest_value = INT_MAX;
	cheapest_node = NULL;
	while (stack)
	{
		if (cheapest_value > stack->push_cost)//si notre cheapest value est plus grande que notre push cost, on la met a jour
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;//notre noeud le moins cher devient celui
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;//la condition devient vraie car c'est bien le noeud le moins couteux
}

void	init_stack_a(t_stack_node *a, t_stack_node *b)
{
	current_index(a);
	current_index(b);
	set_target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}
