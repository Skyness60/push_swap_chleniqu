/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chheniqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:30:30 by chheniqu          #+#    #+#             */
/*   Updated: 2024/11/19 16:48:40 by chheniqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	if (!*s)
		return (0);
	word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			word++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (word);
}

char	*fill_word(const char *str, int start, int end)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static bool	ft_check_free(char **split, int j, int *index)
{
	if (!split[j - 1])
		return ((void)index, true);
	return (*index = -1, false);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	if (!s)
		return (NULL);
	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = fill_word(s, index, i);
			if (ft_check_free(split, j, &index) == true)
				return (ft_free(split, j), NULL);
		}
	}
	return (split[j] = NULL, split);
}
// #include <stdio.h>

// int	main(void)
// {
// 	char	str[] = "Hello world ! toto est malade malheuresement..";
// 	char	**split = ft_split(str, ' ');

// 	for (int i = 0; split[i]; i++)
// 		printf("mot = %s\n", split[i]);
// 	for (int i = 0; split[i]; i++)
// 		free(split[i]);
// 	free(split);
// 	return (0);
// }
