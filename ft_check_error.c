/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:35:42 by chheniqu          #+#    #+#             */
/*   Updated: 2025/01/16 12:35:44 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		if (!str[i])
			return (1);
		while (str[i])
		{
			if (!(str[i] >= '0' && str[i] <= '9'))
				return (1);
			i++;
		}
	}
	return (0);
}

int	ft_check_doubles(t_stack_node *a, int nb) // changer char *s en structure
{
	if (!a) //si notre stack est vide
		return (0);
	while (a)
	{
		if (a->nbr == nb)
			return (1);
		a = a->next;
	}
	return (0);
}

void	ft_free_node(t_stack_node **a)
{
	t_stack_node	*tmp;

	if (!a)
		return ;
	while (*a)
	{
		tmp = (*a)->next;
		(*a)->nbr = 0;
		free(*a);
		*a = tmp;
	}
}

void	ft_error_msg(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
	write(2, "\n", 1);
	exit(1);                                          
}

void	print_stack(t_stack_node *stack)
{
	while (stack)
	{
		printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

// int	main(int argc, char *argv[])
// {
// 	t_stack_node	*stack_a = NULL;

// 	if (argc < 2)
// 	{
// 		printf("Error");
// 		return (1);
// 	}
// 	if (argc == 2)
// 		ft_split(argv[1], ' ');
// 	init_stack(&stack_a, argv);
// 	print_stack(stack_a);
// 	t_stack_node *tmp;
// 	while (stack_a)
// 	{
// 		tmp = stack_a;
// 		stack_a = stack_a->next;
// 		free(tmp);
// 	}
// 	return (0);
// }
