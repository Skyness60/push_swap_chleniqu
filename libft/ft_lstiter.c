/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:31:21 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/18 14:35:44 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
// #include <stdio.h>
// #include <stdlib.h>

// void	print(void *content)
// {
// 	printf("%s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list	*head = ft_lstnew("Un");
// 	t_list	*second = ft_lstnew("Deux");
// 	t_list	*third = ft_lstnew("Trois");
// 	head->next=second;
// 	second->next=third;
// 	ft_lstiter(head, print);
// 	free(head);
// 	free(second);
// 	free(third);
// 	return(0);
// }