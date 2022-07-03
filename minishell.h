/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:29:09 by chfederi          #+#    #+#             */
/*   Updated: 2022/06/28 23:29:13 by chfederi         ###   ########.fr       */
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

typedef struct t_env
{
	struct t_env		*next;
	char				*en;
	int					n;
}t_env;

typedef struct s_data
{
	int		ex;
	int		in;
	int		out;
	t_env	*env1;
	char	**env;
}t_data;

int		env_len(char **env);
t_env	*init_env(t_data *d, t_env *e, char **env);

#endif