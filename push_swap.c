/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:15:36 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 13:35:34 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_sort_stack(t_stack_node *a, t_stack_node *b)
{
	if (stack_len(a) == 2)
		sa(&a, false);
	else if (stack_len(a) == 3)
		sort_three(&a);
	else
		sort_stack(&a, &b);
}

static void	init_la_poubelle(t_poubelle_malloc *poubelle)
{
	poubelle->tete = NULL;
	poubelle->queue = NULL;
	poubelle->taille = 0;
}

void	free_poubelle(t_poubelle_malloc *poubelle)
{
	t_noeux	*current;
	t_noeux	*suivant;

	current = poubelle->tete;
	while (current)
	{
		suivant = current->suivant;
		free(current->ptr_qui_est_malloc);
		free(current);
		current = suivant;
	}
	poubelle->tete = NULL;
	poubelle->queue = NULL;
	poubelle->taille = 0;
}

void	mini_init(t_stack_node *a)
{
	a->nbr = 0;
	a->next = NULL;
	a->poubelle = malloc(sizeof(t_poubelle_malloc));
	if (!a->poubelle)
		return (free(a), exit(1));
	init_la_poubelle(a->poubelle);
}

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	b = NULL;
	a = malloc(sizeof(t_stack_node));
	if (!a)
		return (1);
	mini_init(a);
	if (argc == 1 || (argc == 2 && !argv[1][0])
		|| (argc == 2 && ft_check_number(argv[1]) == 1)
		|| (argc == 2 && ft_atoi_check(argv[1]) == 1))
		return (write(2, "Error\n", 7), 1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!(stack_sorted(a)))
		ft_sort_stack(a, b);
	return (free_poubelle(a->poubelle), free(a->poubelle), free(a), 0);
}
