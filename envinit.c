/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envinit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 21:40:59 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/12 21:59:40 by slaree           ###   ########.fr       */
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
	e->val = s;
	e->ind = n;
	return (e);
}

void	add_list(t_env *e, t_env *new)
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
		add_list(tmp, new_list(env[i], i));
		i++;
	}
	return (tmp);
}

//void	sh_lvl(char **env)
//{
//	int	i;
//
//	i = 0;
//	while (ft_strncmp("SHLVL=", env[i], 5) != 0)
//		i++;
//	env[i] = "SHLVL="
//}