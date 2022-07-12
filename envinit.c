/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:40:59 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/12 20:37:21 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_len(char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	return (i);
}

t_list	*new_list(char *s, int n)
{
	t_list	*e;

	e = malloc(sizeof (t_list));
	if (!e)
		return (NULL);
	e->next = NULL;
	e->en = s;
	e->n = n;
	return (e);
}

void	add_list_env(t_list *e, t_list *new)
{
	while (e->next)
	{
		e = e->next;
	}
	e->next = new;
}

t_list	*init_env(t_data *d, t_list *e, char **env)
{
	int		i;
	t_list	*tmp;

	i = 1;
	d->env = env;
	tmp = new_list(env[0], 0);
	if (!tmp)
		return (NULL);
	while (i < env_len(env) + 1)
	{
		add_list_env(tmp, new_list(env[i], i));
		i++;
	}
	return (tmp);
}
