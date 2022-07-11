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

char	g_mask[3] = "000";

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_parser(char *s, t_data *d)
{
	if (!s)
		return ;
	if (s[0] == 0)
		return ;
	if (ft_strcmp(s, "exit\n") == 0)
	{
		d->ex = 2;
	}
	if (ft_strcmp(s, "pwd\n") == 0)
		pwd();
}

void	sighand(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 1);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **env)
{
	char		*s;
	t_data		d;
	t_env		*e;
	extern int	rl_catch_signals;

	(void )argc;
	(void )argv;
	d.env1 = init_env(&d, e, env);
	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sighand);
		s = readline("$> ");
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		add_history(s);
		rl_catch_signals = 1;
		if (!s)
			break ;
		ft_parser(s, &d);
		free(s);
		if (d.ex == 2)
			break ;
	}
	exit(3);
//	rl_clear_history(s);
}
