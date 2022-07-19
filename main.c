/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/19 02:47:19 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	g_mask[3] = "000";

int	check_builtin(char *s)
{
	if (ft_strcmp(s, "exit\n") == 0)
		return (1);
	if (ft_strcmp(s, "pwd\n") == 0)
		return (1);
	if (ft_strcmp(s, "env\n") == 0)
		return (1);
	if (ft_strcmp(s, "echo\n") == 0)
		return (1);
	if (ft_strcmp(s, "cd\n") == 0)
		return (1);
	if (ft_strcmp(s, "export\n") == 0)
		return (1);
	if (ft_strcmp(s, "unset\n") == 0)
		return (1);
	return (0);
}

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

static void	one_simple_b(t_cmd *cmd, t_data *d)
{
	// is_cmd(cmd);
	if (stacklen(cmd->c_list) == 1 && check_builtin(cmd->c_list->val))
	{
		if (ft_strcmp(cmd->c_list->val, "exit") == 0)
		{
			d->ex = 2;
			return ;
		}
		if (ft_strcmp(cmd->c_list->val, "env") == 0)
		{
			env(d);
			return ;
		}
		if (ft_strcmp(cmd->c_list->val, "pwd") == 0)
		{
			pwd(d);
			return ;
		}
	}
}

void	ft_parser(char *s, t_data *d, t_cmd *cmd)
{
	if (!s)
		return ;
	if (s[0] == 0)
		return ;
	parse_cmd(cmd);
	one_simple_b(cmd, d);
//	if (ft_strcmp(s, "exit\n") == 0)
//	{
//		d->ex = 2;
//		return ;
//	}
//	if (ft_strcmp(s, "env\n") == 0)
//	{
//		env(d);
//		return ;
//	}
//	if (ft_strcmp(s, "pwd\n") == 0)
//	{
//		pwd(d);
//		return ;
//	}
	if (is_pipe(cmd))
	{
//		printf("%s\n", cmd->left_pipe);
		printf("PipE!\n");
	}
//	else
//		printf ("command not found: %s\n", s); //второй фдшник, говорили тебе
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

int	main(int argc, char **argv, char **envp)
{
	char		*s;
	t_data		d;
	t_env		*e;
	extern int	rl_catch_signals;
	t_cmd		*cmd; //добавила структуру, где будут лежать пути к исполняемым файлам команд

	(void )argc;
	(void )argv;
	sh_lvl(envp);
	d.env1 = init_env(&d, e, envp);
	cmd = init_cmd(envp);
	while (1)
	{
		rl_catch_signals = 0;
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, sighand);
		s = readline("$> ");
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
		add_history(s);
		cmd->str = s;// записываю строку из stdin целиком в структуру, наверное ее и будем парсить */
		rl_catch_signals = 1;
		if (!s)
			break ;
		ft_parser(s, &d, cmd);
		free(s);
		if (d.ex == 2)
			break ;
	}
	clear_history();
	exit(3);
}
