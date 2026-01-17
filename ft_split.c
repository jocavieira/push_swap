/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocavieira <jocavieira@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 06:39:36 by jocavieira        #+#    #+#             */
/*   Updated: 2026/01/14 06:39:41 by jocavieira       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	count_word(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static char	*extract_word(const char *s, char c)
{
	size_t	len;
	size_t	i;
	char	*word;

	len = 0;
	i = 0;
	while (s[len] && s[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

static int	check_malloc(char **strings, int i, const char *s, char c)
{
	strings[i] = extract_word(s, c);
	if (!strings[i])
	{
		while (i--)
			free(strings[i]);
		free(strings);
		return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		i;

	i = 0;
	strings = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!s || !strings)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			if (!check_malloc(strings, i, s, c))
				return (NULL);
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	strings[i] = NULL;
	return (strings);
}