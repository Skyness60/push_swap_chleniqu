/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 11:57:57 by chheniqu          #+#    #+#             */
/*   Updated: 2025/01/31 11:58:46 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_stack_node **b, int j)
{
	t_stack_node	*tmp;

	if (!b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	(*b)->prev = NULL;
	tmp->prev = *b;
	if (tmp->next)
		tmp->next->prev = tmp;
	if (j == 0)
		write(1, "sb\n", 3);
}

void	pb(t_stack_node **b, t_stack_node**a, int j)
{
	t_stack_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	(*b)->prev = NULL;
	if (j == 0)
		write(1, "pb\n", 3);
}

void	rb(t_stack_node **b, int j)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!b || !(*b)->next)// si pile vide ou qu'il n'y a qu'un élément dans la liste
		return ;
	tmp = *b;// tmp pointe sur le premier élément de la pile (sinon on perd le haut de la pile)
	*b = (*b)->next;//notre début de liste est maintenant le second élément
	(*b)->prev = NULL;//Le nouveau premier noeud n'a pas d'élément précédent
	last = ft_lstlast(*b);//trouve le dernier élément de pile
	last->next = tmp;//on fait pointer le dernier élément vers tmp(notre premier élément)
	tmp->prev = last;//l'ancien premier noeud pointe vers le dernier noeud
	tmp->next = NULL;//l'ancien premier élément est le dernier
	if (j == 0)
		write(1, "rb\n", 3);
}

void	rrb(t_stack_node **b)
{
	int		i;
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!b || !(*b)->next)
		return ;
	i = 0;
	tmp = *b;//stocke le premier élément de la liste dans tmp
	while ((*b)->next)//parcourir liste jusqu'à la fin
	{
		*b = (*b)->next;
		i++;
	}
	last = *b;//dernier élément de la liste
	last->next = tmp;//le dernier noeud pointe vers le début
	tmp->prev = last;//l'ancien premier noeud pointe vers le dernier noeud
	while (i > 1)// aller à la fin de la boucle 
	{
		tmp = tmp->next;// tmp pointe sur le PREMIER noeud
		i--;// on décrémente i pour arriver à la fin de notre liste
	}
	tmp->next = NULL;//arrivé à la fin, casse boucle pour en faire une liste chainée
	last->prev = NULL;//le nouveau premier noeud n'a pas de précédent
	*b = last;//met à jour le début de la liste pour pointer vers last
}
