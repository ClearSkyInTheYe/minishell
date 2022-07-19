/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:47:39 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/19 00:34:12 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ctoi(char *s)
{
	long	i;
	int		x;
	int		a;

	x = 0;
	i = 0;
	a = 1;
	if (s[0] == '-')
	{
		a = -1;
		x++;
	}
	if (s[0] == '+')
		x++;
	while (s[x])
	{
		i = i * 10;
		i += s[x++] - '0';
	}
	return (i * a);
}

static int	ft_neglen(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0 && n >= -9)
	{
		i = 2;
		return (i);
	}
	n = -n;
	while ((n / 10) > 9)
	{
		n = n / 10;
		i++;
	}
	i = i + 3;
	return (i);
}

static	int	ft_nlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
	{
		i = 1;
		return (i);
	}
	if (n > 0)
	{
		if (n <= 9 && n > 0)
		{
			i = 1;
			return (i);
		}
		while ((n / 10) > 9)
		{
			n = n / 10;
			i++;
		}
		i = i + 2;
	}
	else
		i = ft_neglen(n);
	return (i);
}

char	*ft_itoa(int n)
{
	unsigned int	c;
	char			*s;
	int				i;
	int				l;
	long			b;

	b = n;
	i = ft_nlen(n);
	l = ft_nlen(n) - 1;
	s = malloc(sizeof (char) * (i + 1));
	if (s == NULL)
		return (NULL);
	if (n < 0)
		n = -n;
	c = n;
	while (l >= 0)
	{
		s[l] = c % 10 + 48;
		c = c / 10;
		l--;
	}
	if (b < 0)
		s[l + 1] = '-';
	s[i] = '\0';
	return (s);
}

int	stacklen(t_env	*c_list)
{
	int	i;

	if (!c_list)
		return (0);
	i = -1;
	while (c_list)
	{
		i++;
		c_list = c_list->next;
	}
	return (i);
}
