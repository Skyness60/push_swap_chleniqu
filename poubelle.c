/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poubelle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sami <sami@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:00:30 by sami              #+#    #+#             */
/*   Updated: 2025/02/19 17:03:00 by sami             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	is_ptr_in_trash(t_poubelle_malloc *poubelle, void *pointeur)
{
	t_noeux	*current;

	current = poubelle->tete;
	while (current)
	{
		if (current->ptr_qui_est_malloc == pointeur)
			return (true);
		current = current->suivant;
	}
	return (false);
}

void	add_pointeur_malloc(t_poubelle_malloc *poubelle, void *pointeur)
{
	t_noeux	*new;

	if (!pointeur || is_ptr_in_trash(poubelle, pointeur))
		return ;
	new = malloc(sizeof(t_noeux));
	if (!new)
		return ;
	new->ptr_qui_est_malloc = pointeur;
	new->suivant = NULL;
	if (poubelle->queue)
		poubelle->queue->suivant = new;
	else
		poubelle->tete = new;
	poubelle->queue = new;
	poubelle->taille++;
}
