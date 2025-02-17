/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:33:18 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/22 10:46:14 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	src[] = "Hello world";
// 	char	dst[20];
// 	size_t	result = strlcpy(dst, src,sizeof);
// 	printf("Source: %s\nDestination: %s\n", src, dest);
// 	return (0);
// }
