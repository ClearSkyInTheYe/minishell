/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:32 by slaree            #+#    #+#             */
/*   Updated: 2022/07/15 16:53:51 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l;
	size_t	i;
	char	*sub;

	if (!s || len <= 0 || start >= ft_strlen(s))
	{
		sub = "";
		return (sub);
	}
	l = ft_strlen(&s[start]);
	if (l < len)
		len = l;
	sub = (char *) malloc(sizeof (char) * (len + 1));
	if (!sub)
		return (NULL);
	i = start;
	while (s[i] && (i - start) < len)
	{
		sub[i - start] = s[i];
		i++;
	}
	sub[i - start] = '\0';
	return (sub);
}
