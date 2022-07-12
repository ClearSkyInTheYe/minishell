
#include "env.h"

char	*parse_cmd(char *s)
{
	char	**arr;
	int		len;

	arr = ft_split(s, ' '); //if (!arr)
	len = ft_count_words(s, ' ');
	

}

int	is_pipe(t_cmd *cmd)
{
    char	*line;
	char	*res;
    int		i;

	i = -1;
    line = cmd->str;
    while (line[++i])
    {
        if (line[i] == '|')
		{
			while (*line != '|')
			{
				*res = *line;
				line++;
				res++;
			}
			*res = '\0';
			cmd->is_pipe = 1;
			cmd->left_pipe = res;
			return (1);
		}	
    }
	*res = '\0';
	return (0);
}


// char *is_cmd(t_cmd *cmd)
// {
//     char *tmp;
//     char *c;

//     while (cmd->paths)
//     {
//         tmp = ft_strjoin(cmd->paths, "/");
//         c = ft_strjoin(tmp, //cmd);// put splitted word or command
//         free(tmp);
//         if (access(c, 0) == 0)
//             return (c);
//         free(c);
//         cmd->paths++;
//     }
//     return (NULL);
// }