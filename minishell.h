/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:29:09 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/12 20:37:45 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <fcntl.h>
//# include <ios.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/stat.h>
//# include <dir.h>
# include <stdint.h>
# include "dash/env.h"

typedef struct t_list
{
	struct t_list		*next;
	char				*en;
	int					n;
}t_list;

typedef struct s_data
{
	int		ex;
	int		in;
	int		out;
	t_list	*env1;
	char	**env;
}t_data;

//char	g_mask[3] = "000";

int		env_len(char **env);
t_list	*init_env(t_data *d, t_list *e, char **env);
void	rl_replace_line(const char *text, int clear_undo);
void	sighand(int sig);
int		ft_strcmp(char *s1, char *s2);
void	pwd(t_data *d);
void	env(t_data *d);

#endif