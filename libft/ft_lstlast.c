/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:39:18 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 17:23:19 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	t_list	*head = ft_lstnew("Un");
// 	t_list	*second = ft_lstnew("Deux");
// 	t_list	*third = ft_lstnew("Trois");
// 	head->next=second;
// 	second->next=third;
// 	t_list	*last = ft_lstlast(head);
// 	printf("Last element = %s\n", (char *)last->content);
// 	free(head);
// 	free(second);
// 	free(third);
// 	return(0);
// }