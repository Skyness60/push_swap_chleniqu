/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:50:43 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 17:02:13 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*newstr;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (start < end && ft_strchr(set, s1[start]))
		start++;
	while (start < end && ft_strchr(set, s1[end - 1]))
		end--;
	newstr = (char *)malloc(end - start + 1);
	if (!newstr)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		newstr[i] = s1[start + i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	const char	*s1 = " \t\nHello world! \t\n\n";
// 	const char	*set = " \t\n";

// 	char		*result = ft_strtrim(s1, set);
// 	printf("original = %s\n", s1);
// 	printf("result = %s\n", result);
// 	free(result);
// 	return (0);
// }