/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:19:15 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/21 16:53:51 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	cc;

	i = 0;
	cc = (char)c;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != cc)
	{
		if (s[i] == cc)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *)&s[i]);
	return (NULL);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "chjbg kgwnshuw";
// 	char	c = 'k';

// 	printf("%s\n", ft_strchr(str, c));
// 	return (0);
// }
