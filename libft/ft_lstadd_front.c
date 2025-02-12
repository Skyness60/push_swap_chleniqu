/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:23:59 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/21 16:02:19 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
// #include <stdio.h>
// int main(void)
// {
// 	t_list *head = ft_lstnew("Deuxieme");
// 	t_list *new_node = ft_lstnew("Premier");

// 	ft_lstadd_front(&head, new_node);
// 	printf("Premier élément : %s\n", (char *)head->content);
// 	printf("Deuxieme élément : %s\n", (char *)head->next->content);
// 	free(new_node);
// 	return (0);
// }