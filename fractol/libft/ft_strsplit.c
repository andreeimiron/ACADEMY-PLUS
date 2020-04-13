/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmiron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 20:49:42 by anmiron           #+#    #+#             */
/*   Updated: 2017/01/14 13:27:19 by anmiron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_words(const char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*get_word(const char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (char*)malloc(sizeof(char) * 500);
	while (str[i] && str[i] != c)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_strsplit(const char *s, char c)
{
	char	**split;
	int		words;
	int		i;

	i = 0;
	words = count_words(s, c);
	split = (char**)malloc(sizeof(char*) * words + 1);
	if (split == NULL)
		return (NULL);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			split[i] = get_word(s, c);
			s = s + ft_strlen(split[i]);
			i++;
		}
	}
	split[i] = NULL;
	return (split);
}
