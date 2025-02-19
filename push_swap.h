/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:07:58 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 12:39:50 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_noeux
{
	void			*ptr_qui_est_malloc;
	struct s_noeux	*suivant;
}				t_noeux;

typedef struct s_poubelle_malloc
{
	t_noeux		*tete;
	t_noeux		*queue;
	size_t		taille;
}	t_poubelle_malloc;

typedef struct s_stack_node
{
	int					index;
	int					nbr;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	t_poubelle_malloc	*poubelle;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
}	t_stack_node;

int				ft_atoi_check(const char *str);
int				ft_check_number(char *str);
int				ft_check_doubles(t_stack_node *a, int nb);
void			ft_error_msg(char *str);
void			init_stack_a(t_stack_node **a, char **argv);
void			init_node_a(t_stack_node *a, t_stack_node *b);
void			init_node_b(t_stack_node *a, t_stack_node *b);
void			add_node(t_stack_node **stack, int nb);
void			ft_stackaddback(t_stack_node **lst, t_stack_node *new);
void			ft_free_node(t_stack_node **a);
void			ft_lstaddback(t_stack_node **lst, t_stack_node *new);
t_stack_node	*ft_lstlast(t_stack_node *lst);
void			sa(t_stack_node **a, int j);
void			sb(t_stack_node **b, int j);
void			pa(t_stack_node **a, t_stack_node**b, int j);
void			pb(t_stack_node **b, t_stack_node**a, int j);
void			ra(t_stack_node **a, int j);
void			rb(t_stack_node **b, int j);
void			rra(t_stack_node **a, int j);
void			rrb(t_stack_node **b, int j);
void			rr(t_stack_node **a, t_stack_node **b, int j);
void			rrr(t_stack_node **a, t_stack_node **b, int j);
void			rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b,
					t_stack_node *cheapest_node);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last_node(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **stack, t_stack_node *top_node,
					char stack_name);
void			print_stack(t_stack_node *stack);
void			sort_three(t_stack_node **a);
void			sort_stack(t_stack_node **a, t_stack_node **b);
void			add_pointeur_malloc(t_poubelle_malloc *poubelle, \
	void *pointeur);
void			free_poubelle(t_poubelle_malloc *poubelle);
#endif
