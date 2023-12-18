/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:18:09 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/11/05 11:19:41 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_first_occurrence(const char *s, char c)
{
	int	index;

	index = 0;
	while (*s)
	{
		if (*s == c)
			return (index);
		s++;
		index++;
	}
	return (index);
}

static void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	count_words(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static char	**lines_save(char const *s, char c, char **result, int word_count)
{
	int	i;

	i = 0;
	while (i < word_count)
	{
		while (*s == c)
			s++;
		result[i] = ft_substr(s, 0, find_first_occurrence(s, c));
		if (!result[i])
		{
			ft_free_split(result);
			return (NULL);
		}
		while (*s && *s != c)
			s++;
		i++;
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		word_count;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc((word_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (lines_save(s, c, result, word_count));
}
