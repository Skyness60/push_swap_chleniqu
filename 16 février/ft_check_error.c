/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <chheniqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:35:42 by chheniqu          #+#    #+#             */
/*   Updated: 2025/02/17 13:08:01 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' || ((str[i] == '+' || str[i] == '-')
				&& !(str[i + 1] == '-' || str[i + 1] == '+')))
			i++;
		else if (!str[i])
			return (1);
		else if (!(str[i] >= '0' && str[i] <= '9')
			|| ((str[i] >= '0' && str[i] <= '9')
				&& (str[i + 1] == '-' || str[i + 1] == '+'))
			|| ((str[i] == '-' || str[i] == '+')
				&& (str[i + 1] == '-' || str[i + 1] == '+')))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_doubles(t_stack_node *a, int nb)
{
	if (!a)
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
