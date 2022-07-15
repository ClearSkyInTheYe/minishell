/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:48:42 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/12 21:41:45 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	pwd(t_data *d)
{
	t_env	*e;
	char	*s;

	e = d->env1;
	while (ft_strncmp("PWD", e->val, 3) != 0)
		e = e->next;
	s = malloc(sizeof (char ) * ft_strlen(e->val) + 1);
	if (!s)
		return (1);
	getcwd(s, ft_strlen(e->val));
	printf("%s\n", s);
	free(s);
	return (0);
}

void	env(t_data *d)
{
	t_env	*e;

	e = d->env1;
	while (e->next)
	{
		printf("%s\n", e->val);
		e = e->next;
	}
}
