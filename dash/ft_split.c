/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:44:27 by slaree            #+#    #+#             */
/*   Updated: 2022/07/11 20:15:34 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count ++;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static char	**ft_free_array(char **array, int i)
{
	while (i--)
		free (array[i]);
	free (array);
	array = NULL;
	return (array);
}

static char	*ft_wd(char const *str, char c)
{
	int		i;
	char	*wd;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc (sizeof (char) * (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (*str && *str != c)
	{
		wd[i] = *str;
		i++;
		str++;
	}
	wd[i] = '\0';
	return (wd);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	size_t	count;
	size_t	i;

	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	words = (char **) malloc (sizeof (char *) * (count + 1));
	if (words == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s && *s == c)
			s++;
		words[i] = ft_wd(s, c);
		if (words[i] == NULL)
			ft_free_array (words, i);
		while (*s && *s != c)
			s++;
		i++;
	}
	words[i] = NULL;
	return (words);
}
