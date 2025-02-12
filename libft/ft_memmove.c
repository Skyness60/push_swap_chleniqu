/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:41:00 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/21 18:45:27 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && ! src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			*(char *)(dest + i) = *(char *)(src + i);
			i++;
		}
	}
	return (dest);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 	char	str[50] = "Hello world";
// 	char	dest[50] = "bbbbbbbbbbbbla";

// 	ft_memmove(dest, str, 10);
// 	printf("%s\n", dest);
// 	char	strs[50] = "Hello world";
// 	char	dests[50] = "bbbbbbbbbbbbla";
// 	memmove(dests, strs, 10);
// 	printf("%s\n", dests);
// 	return (0);
// }
