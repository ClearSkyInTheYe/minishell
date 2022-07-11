#include "env.h"

// t_cmd *init_cmd(char **envp)

char	*find_path(char **envp)
{
	while (*envp && ft_strncmp("PATH", *envp, 4))
		envp++;
	if (!*envp)
	{
        ft_putstr_fd("FIND_PATH ERROR\n", 2);//redo out for particular cmd
		exit (1);
	}
	return (*envp + 5);
}

char *get_cmd(char **paths, char *cmd)
{
    char *tmp;
    char *c;

    while (*paths)
    {
        tmp = ft_strjoin(*paths, "/");
        c = ft_strjoin(tmp, cmd);
        free(tmp);
        if (access(c, 0) == 0)
            return (c);
        free(c);
        paths++;
    }
    return (NULL);
}

t_cmd *init_cmd(char **envp)
{
    t_cmd *cmd;

    cmd = malloc(sizeof(t_cmd));
    cmd->paths = find_path(envp);
    cmd->p = ft_count_words(cmd->paths, ':'); //cmd->p - это количество путей в path
    cmd->cmd_paths = ft_split(cmd->paths, ':'); //free
    // cmd->str = str; //запишем строку как есть в структуру для начала 

    // int i = -1;
    // while (++i < cmd->p)
    //     printf("%s\n", cmd->cmd_paths[i]);
    return (cmd);
}