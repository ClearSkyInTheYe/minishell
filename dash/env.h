/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaree <slaree@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:59:54 by chfederi          #+#    #+#             */
/*   Updated: 2022/07/19 02:36:02 by slaree           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

#include "../minishell.h"
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>


typedef struct	s_cmd
{
	char			**env;
	char			*paths;
	char			**cmd_paths;
	int				p;
	char			*str;
	int				is_pipe;
	char			*left_pipe;
	char			*command;
	struct t_env 	*c_list;
	struct t_env	*exec_list;
	// int fd[2];
}t_cmd;

//cmd.c
char	*find_path(char **envp);
char	*get_cmd(char **paths, char *cmd);
t_cmd	*init_cmd(char **envp);
// int	execute_simple_cmd(t_cmd *cmd, t_data *data);
int	execute_simple_cmd(t_cmd *cmd, char **envp);

//parse.c
int	parse_cmd(t_cmd *cmd);
int	is_pipe(t_cmd *cmd);
int is_cmd(t_cmd *cmd);

//ft_split.c
size_t	ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);

//libft/
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

int		ft_isspace(char *s, int i);

#endif
