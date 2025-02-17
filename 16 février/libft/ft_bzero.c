/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:03:18 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/21 18:35:48 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !n)
		return ;
	str = (char *) s;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	buffer[20] = "Hello world";
	char	ft_buffer[20] = "Hello world";
	int		i;

	bzero(buffer, 5);
	ft_bzero(ft_buffer, 5);
	i = 0;
	while (i < 20)
	{
		if (ft_buffer[i] == '\0')
			printf(".");
		else
			printf("%c", ft_buffer[i]);
		i++;
	}
	printf("\n");
	return (0);
}
*/
