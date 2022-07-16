/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:29:09 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/15 20:12:50 by slaree           ###   ########.fr       */
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

typedef struct t_env
{
	struct t_env		*next;
	char				*val;
	int					ind;
}t_env;

typedef struct s_data
{
	int		ex;
	int		in;
	int		out;
	t_env	*env1;
	char	**env;
}t_data;

//char	g_mask[3] = "000";


//envinit.c
int		env_len(char **env);
t_env	*new_list(char *s, int n);
void	add_list(t_env *e, t_env *new);
t_env	*init_env(t_data *d, t_env *e, char **env);
void	rl_replace_line(const char *text, int clear_undo);
void	sighand(int sig);
int		ft_strcmp(char *s1, char *s2);
int		pwd(t_data *d);
void	env(t_data *d);
int		ctoi(char *s);
char	*ft_itoa(int n);
void	sh_lvl(char **env);
int		stacklen(t_env	*c_list);

#endif