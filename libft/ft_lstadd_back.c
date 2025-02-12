/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:44:00 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 17:10:49 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			tmp = *lst;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
}
// #include <stdio.h>
// int main(void)
// {
// 	t_list *head = ft_lstnew("Premier");
// 	t_list *new_node = ft_lstnew("Dernier");

// 	ft_lstadd_back(&head, new_node);
// 	printf("Premier élément : %s\n", (char *)head->content);
// 	printf("Dernier élément : %s\n", (char *)head->next->content);
// 	free(head);
// 	free(new_node);
// 	return (0);
// }