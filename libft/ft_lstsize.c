/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:36:09 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/18 13:38:03 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	t_list	*head = ft_lstnew("Un");
// 	t_list	*last = ft_lstnew("Deux");
// 	head->next = last;
// 	printf("Size = %d\n", ft_lstsize(head));
// 	free(head);
// 	free(last);
// 	return (0);
// }