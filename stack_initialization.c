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

void	init_stack_a(t_stack_node **a, char *argv)
{
	int		i;
	long	nb;

	i = 0;
	nb = 0;
	while (argv[i])
	{
		if (ft_check_number(argv[i]))
			return (ft_free_node(a), ft_error_msg("Error\n number is not digit"));
		if (ft_atoi_check(argv[i]) == 1)
			return (ft_free_node(a), ft_error_msg("Error\n INT MAX or INT MIN"));
		nb = ft_atoi(argv[i]);
		if (ft_check_doubles(*a, nb))
			return (ft_free_node(a), ft_error_msg("Error\n double in args"));
		add_node(a, (int)nb);
		i++;
	}
}

void	ft_stackaddback(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
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
	node->next = NULL;//dernier noeud de la liste
	node->nbr = nb;//remplir node
	node->cheapest = 0;
	if (!(*stack))//si notre stack est vide
	{
		*stack = node;
		node->next = NULL;//unique noeud, donc le noeud d'avant est null
	}
	else//si notre stack a deja des elements, on va chercher 
	{
		ft_stackaddback(stack, node);
	}
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
