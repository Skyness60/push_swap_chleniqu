/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:50:14 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 16:49:46 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	j = 0;
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[j] != '\0' && (i + j) < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str_src[] = "blablbla";
// 	char	str_dst[] = " b ";
// 	size_t	ft_result = ft_strlcat(str_dst, str_src, sizeof(str_dst));

// 	printf("ft_strlcat = %s, %zu\n", str_dst, ft_result);
// 	return (0);
// }