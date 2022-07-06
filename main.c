/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/06/28 23:38:18 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_parser(char *s, t_data *d)
{
	char	*a;

	if (!s)
		exit(3);
	if (ft_strcmp(s, "exit") == 0)
	{
		d->ex = 2;
	}
}

void	sighand(int sig)
{
//	signal(SIGQUIT, SIG_IGN);
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line(" ", 1);
		rl_on_new_line();
		rl_redisplay();
	}
//	if (sig == SIG_DFL)
//		exit(3);
}

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_data	d;
	t_env	*e;
	char	*a;

//	d = ft_init(d);
	d.ex = 1;
	signal(SIGINT, sighand);
//	signal(SIGQUIT, sighand);
	e = init_env(&d, e, env);
	while (1)
	{
		s = readline("$> ");
//		printf("%s\n", s);
//		if (open("stdin", 1) == -1)
//			break ;
		ft_parser(s, &d);
//		if (d.ex != 2)
//			signal(SIGQUIT, SIG_IGN);
//		if (d.ex == 2)
//			break ;
	}
	printf("%i\n", d.ex);
//	while (e->next)
//	{
//		printf("1%s\n", e->en);
//		e = e->next;
//	}
}
