/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 12:36:42 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 15:11:06 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;

	alloc = malloc(nmemb * size);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, nmemb * size);
	return (alloc);
}
// #include <stdio.h>

// int	main(void)
// {
// 	int *std_ptr = (int *)calloc(3, sizeof(int));
// 	int *ft_ptr = (int *)ft_calloc(3, sizeof(int));

// 	printf("Calloc: %d %d %d\n", std_ptr[0], std_ptr[1], std_ptr[2]);
// 	printf("Ft_calloc: %d %d %d\n", ft_ptr[0], ft_ptr[1], ft_ptr[2]);
// 	free(std_ptr);
// 	free(ft_ptr);
// }
