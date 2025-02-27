/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_initialization.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:57:37 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/05 10:57:38 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	add_node_end(t_stack_node **stack, int n)
// {
// 	t_stack_node	*node; 
// 	t_stack_node	*last_node;

// 	if (!stack)
// 		return ;
// 	node = malloc(sizeof(t_stack_node));
// 	if (!node)
// 		return ;
// 	node->next = NULL;
// 	node->nbr = n;
// 	node->cheapest = 0;
// 	if (!(*stack))
// 	{
// 		*stack = node;
// 		node->prev = NULL;
// 	}
// 	else
// 	{
// 		last_node = find_last_node(*stack);
// 		last_node->next = node;
// 		node->prev = last_node;
// 	}
// }

void	init_stack_a(t_stack_node **a, char **argv)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (ft_check_number(argv[i]))
			return (ft_free_node(a), ft_error_msg("Error"));
		if (ft_atoi_check(argv[i]) == 1)
			return (ft_free_node(a), ft_error_msg("Error"));
		nb = ft_atoi(argv[i]);
		if (*a && ft_check_doubles(*a, nb))
			return (free_poubelle((*a)->poubelle), free((*a)->poubelle), \
			free(*a), ft_error_msg("Error"));
		add_node(a, (int)nb);
		i++;
	}
}

void	ft_stackaddback(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->next = NULL;
	}
}

void	add_node(t_stack_node **stack, int nb)
{
	t_stack_node	*node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->next = NULL;
	node->nbr = nb;
	node->cheapest = 0;
	add_pointeur_malloc((*stack)->poubelle, node);
	if (!(*stack))
	{
		*stack = node;
		node->next = NULL;
	}
	else
		ft_stackaddback(stack, node);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

//mettre le noeud en haut de la pile
void	prep_for_push(t_stack_node **stack, t_stack_node *top_node,
						char stack_name)
{
	while (top_node != *stack)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
