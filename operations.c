/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:53:32 by chheniqu          #+#    #+#             */
/*   Updated: 2025/01/23 10:53:37 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node *ft_lstlast(t_stack_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstaddback(t_stack_node **lst, t_stack_node *new)
{
	t_stack_node	*tmp;

	if (lst)
	{
		if (*lst == NULL)
		{
			*lst = new;
			new->prev = NULL;
		}
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
	}
}

void	sa(t_stack_node **a, int j)
{
	t_stack_node	*tmp;

	if (!a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	(*a)->prev = NULL;
	tmp->prev = *a;
	if (tmp->next)
		tmp->next->prev = tmp;
	if (j == 0)
		write(1, "sa\n", 3);
}

void	pa(t_stack_node **a, t_stack_node**b, int j)
{
	t_stack_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	(*a)->prev = NULL;
	if (j == 0)
		write(1, "pa\n", 3);
}

void	ra(t_stack_node **a, int j)
{
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!a || !(*a)->next)// si pile vide ou qu'il n'y a qu'un élément dans la liste
		return ;
	tmp = *a;// tmp pointe sur le premier élément de la pile (sinon on perd le haut de la pile)
	*a = (*a)->next;//notre début de liste est maintenant le second élément
	(*a)->prev = NULL;//Le nouveau premier noeud n'a pas d'élément précédent
	last = ft_lstlast(*a);//trouve le dernier élément de pile
	last->next = tmp;//on fait pointer le dernier élément vers tmp(notre premier élément)
	tmp->prev = last;//l'ancien premier noeud pointe vers le dernier noeud
	tmp->next = NULL;//l'ancien premier élément est le dernier
	if (j == 0)
		write(1, "ra\n", 3);
}

void	rra(t_stack_node **a)
{
	int		i;
	t_stack_node	*tmp;
	t_stack_node	*last;

	if (!a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a;//stocke le premier élément de la liste dans tmp
	while ((*a)->next)//parcourir liste jusqu'à la fin
	{
		*a = (*a)->next;
		i++;
	}
	last = *a;//dernier élément de la liste
	last->next = tmp;//le dernier noeud pointe vers le début
	tmp->prev = last;//l'ancien premier noeud pointe vers le dernier noeud
	while (i > 1)// aller à la fin de la boucle 
	{
		tmp = tmp->next;// tmp pointe sur le PREMIER noeud
		i--;// on décrémente i pour arriver à la fin de notre liste
	}
	tmp->next = NULL;//arrivé à la fin, casse boucle pour en faire une liste chainée
	last->prev = NULL;//le nouveau premier noeud n'a pas de précédent
	*a = last;//met à jour le début de la liste pour pointer vers last
}

// Fonction pour afficher la pile
void print_stack(t_stack_node *stack, const char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d -> ", stack->nbr);
        stack = stack->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire de la pile
void free_stack(t_stack_node *stack)
{
    t_stack_node *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int main(void)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Crée une pile `a` avec quelques éléments
    for (int i = 1; i <= 5; i++)
    {
        t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
        new_node->nbr = i;
        new_node->next = a;
        a = new_node;
    }

    // Affiche la pile `a` initiale
    print_stack(a, "a (initial)");

    // Teste swap_a
    swap_a(&a, 0);
    print_stack(a, "a after swap_a");

    // Teste rotate_a
    rotate_a(&a, 0);
    print_stack(a, "a after rotate_a");

    // Teste reverse_rotate_a
    reverse_rotate_a(&a);
    print_stack(a, "a after reverse_rotate_a");

    // Teste push_a (nécessite une pile `b`)
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    new_node->nbr = 10;
    new_node->next = NULL;
    b = new_node;
    print_stack(b, "b (initial)");
    push_a(&a, &b, 0);
    print_stack(a, "a after push_a");
    print_stack(b, "b after push_a");

    // Libère la mémoire
    free_stack(a);
    free_stack(b);

    return 0;
}

void print_stack_with_prev(t_stack_node *stack, const char *name)
{
    printf("%s: ", name);
    while (stack)
    {
        printf("%d (prev: %p) -> ", stack->nbr, (void *)stack->prev);
        stack = stack->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire de la pile
void free_stack(t_stack_node *stack)
{
    t_stack_node *tmp;
    while (stack)
    {
        tmp = stack;
        stack = stack->next;
        free(tmp);
    }
}

int main(void)
{
    t_stack_node *a = NULL;
    t_stack_node *b = NULL;

    // Crée une pile `a` avec quelques éléments
    for (int i = 1; i <= 5; i++)
    {
        t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
        new_node->nbr = i;
        new_node->next = NULL;
        new_node->prev = NULL;
        ft_lstaddback(&a, new_node);
    }

    // Affiche la pile `a` initiale avec les pointeurs `prev`
    print_stack_with_prev(a, "a (initial)");

    // Teste swap_a
    swap_a(&a, 0);
    print_stack_with_prev(a, "a after swap_a");

    // Teste rotate_a
    rotate_a(&a, 0);
    print_stack_with_prev(a, "a after rotate_a");

    // Teste reverse_rotate_a
    reverse_rotate_a(&a);
    print_stack_with_prev(a, "a after reverse_rotate_a");

    // Teste push_a (nécessite une pile `b`)
    t_stack_node *new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    new_node->nbr = 10;
    new_node->next = NULL;
    new_node->prev = NULL;
    b = new_node;
    print_stack_with_prev(b, "b (initial)");
    push_a(&a, &b, 0);
    print_stack_with_prev(a, "a after push_a");
    print_stack_with_prev(b, "b after push_a");

    // Libère la mémoire
    free_stack(a);
    free_stack(b);

    return 0;
}