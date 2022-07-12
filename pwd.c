/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:48:42 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/12 20:38:06 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(t_data *d)
{
	t_list	*e;

	e = d->env1;
	while (ft_strncmp("PWD", e->en, 3) != 0)
		e = e->next;
	printf("%s\n", e->en + 4);
}

void	env(t_data *d)
{
	t_list	*e;

	e = d->env1;
	while (e->next)
	{
		printf("%s\n", e->en);
		e = e->next;
	}
}
