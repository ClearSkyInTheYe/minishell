/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:45:17 by slaree            #+#    #+#             */
/*   Updated: 2022/07/11 20:18:40 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((ptr1[i] || ptr2[i]) && i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
