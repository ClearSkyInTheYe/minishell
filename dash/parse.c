
#include "env.h"

int	parse_cmd(t_cmd *cmd)
{
	char	**arr;
	int		len;
	int		i;

	arr = ft_split(cmd->str, ' '); //if (!arr)
	len = ft_count_words(cmd->str, ' ');
	i = 0;
	cmd->c_list = new_list(arr[i], i);
		if (!cmd->c_list)
			return (1);
	while (arr[i++])
	{
		add_list(cmd->c_list, new_list(arr[i], i));
	}
	return (0);
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