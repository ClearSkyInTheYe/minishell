
#include "env.h"

// t_env	*new_list(char *s, int n)
// {
// 	t_env	*e;

// 	e = malloc(sizeof (t_env));
// 	if (!e)
// 		return (NULL);
// 	e->next = NULL;
// 	e->val= s;
// 	e->ind = n;
// 	return (e);
// }

// void	add_list(t_env *e, t_env *new)
// {
// 	while (e->next)
// 	{
// 		e = e->next;
// 	}
// 	e->next = new;
// }
//////////////////////////////////////////////////////////////////

int	parse_cmd(t_cmd *cmd)
{
	char	**arr;
//	int		len;
	int		i;

	arr = ft_split(cmd->str, ' ');
	if (!arr)
		return (0);
//	len = ft_count_words(cmd->str, ' '); // мне кажется что это тут не нужно
	i = 0;
	cmd->c_list = new_list(arr[i], i);
	if (!cmd->c_list)
		return (1);
	while (arr[i++])
	{
		add_list(cmd->c_list, new_list(arr[i], i));
	}
	free(arr);//каждый элемент масива возможно стоит фришить но тогда в листы пихать малоченые строки
	return (0);
}

char	*ft_cpystr(char *src, int len)
{
	char	*dst;
	int		i;
//	char	*tmp;

	i = 0;
	dst = malloc(sizeof (char ) * len);
	if (!dst)
		return (NULL);
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
//	tmp = dst;
//	free(dst);
	return (dst);
}

int	is_pipe(t_cmd *cmd)
{
    char	*line;
	char	*res;
	int		len;
    int		i;

	i = 0;
	// res = "\0";
    line = cmd->str;
	len = ft_strlen(line);
	while (line[i] && line[i] != '|')
		i++;
	if (i == len)
	{
		cmd->command = line;
		return (0);
	}
//	printf("%s\n", line);
//	return (2);
	res = ft_cpystr(line, i);// ваще наверное субстром стоило))
//	cmd->left_pipe = ft_cpystr(line, i);
	if ((ft_strlen(res) + 1) == len || ft_isspace(line, i) || !res)
	{
		return (3); // to check if waiting mode is needed
	}
//	if ((ft_strlen(cmd->left_pipe) + 1) == len || ft_isspace(line, i) || !cmd->left_pipe)
//	{
//		return (3); // to check if waiting mode is needed
//	}
	cmd->left_pipe = res;
//	printf("%s\n", res);
//	free(res);
	line = ft_substr(line, i + 1, len - i);
	return (1);
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

// int main(int argc, char **argv, char **envp)
// {
// 	// char *path;

// 	// path = getenv("PATH");
// 	// printf("%s\n", path);


// 	t_cmd *cmd;

// 	cmd = init_cmd(envp);
	

// 	char *s = "ls";
// 	cmd->str = s;
// 	printf("%d\n",is_pipe(cmd));

// 	execute_simple_cmd(cmd, envp);

// }