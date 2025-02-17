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

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0])
		|| (argc == 2 && ft_check_number(argv[1]) == 1)
		|| (argc == 2 && ft_atoi_check(argv[1]) == 1))
	{
		write(2, "Error\n", 7);
		return (1);
	}
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		init_stack_a(&a, argv);
	}
	else
		init_stack_a(&a, argv + 1);
	if (!(stack_sorted(a)))
	{
		ft_sort_stack(a, b);
	}
	return (ft_free_node(&a), ft_free_node(&b), 0);
}
