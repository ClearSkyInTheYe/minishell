/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:40:59 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/03 21:41:02 by chfederi         ###   ########.fr       */
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

t_env	*new_list(char *s, int n)
{
	t_env	*e;

	e = malloc(sizeof (t_env));
	if (!e)
		return (NULL);
	e->next = NULL;
	e->en = s;
	e->n = n;
	return (e);
}

void	add_list_env(t_env *e, t_env *new)
{
	while (e->next)
	{
		e = e->next;
	}
	e->next = new;
}

t_env	*init_env(t_data *d, t_env *e, char **env)
{
	int		i;
	t_env	*tmp;

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
