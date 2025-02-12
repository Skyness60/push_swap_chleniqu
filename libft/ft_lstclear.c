/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:01:29 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 17:21:02 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		(*lst) = tmp;
	}
}
// #include <stdio.h>
// #include <stdlib.h>

// void	del(void *content)
// {
// 	free(content);
// }

// // int	main(void)
// // {
// // 	t_list *head = ft_lstnew(malloc(10));
// // 	t_list *second = ft_lstnew(malloc(20));
// // 	t_list *third = ft_lstnew(malloc(30));
// // 	head->next = second;
// // 	second->next = third;
// // 	ft_lstclear(&head, del);
// // 	if (!head)
// // 		printf("Liste complètement libérée.\n");
// // 	else
// // 		printf("Erreur : la liste n'a pas été correctement libérée.\n");
// // 	return (0);
// // }
