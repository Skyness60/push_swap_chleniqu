/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:15:36 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/07 10:15:40 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (1);
	else if (argc == 2)
		ft_split(argv[1], ' ');
	if (!(stack_sorted(*a)))
	{
		if (stack_len(*a) == 2)
			swap_a(&a, false);
		else if (stack_len(*a) == 3)
			sort_three(&a);
	}
}

