#ifndef ENV_H
# define ENV_H

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>

typedef struct s_cmd
{
    char *paths;
    char **cmd_paths;
    int p;
    char    *cmd;
    // int fd[2];
} t_cmd;

//cmd.c
char	*find_path(char **envp);
char *get_cmd(char **paths, char *cmd);

//libft/
size_t	ft_count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);


#endif