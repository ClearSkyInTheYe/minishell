
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
	int		len;
	int		i;

	arr = ft_split(cmd->str, ' ');
	if (!arr)
		return (0);
	len = ft_count_words(cmd->str, ' '); // это нужно 
	i = 0;
	cmd->c_list = new_list(arr[i], i);
	if (!cmd->c_list)
		return (1);
	while (++i < len)
		add_list(cmd->c_list, new_list(arr[i], i));
	// free(arr);//каждый элемент масива возможно стоит фришить но тогда в листы пихать малоченые строки
	return (0);
}
//////////////////////////////////////////////////////////////////
//int	parse_cmd(t_cmd *cmd)
//{
//	char	*arr;
//	int		len;
//	int		i;
//
////	arr = ft_split(cmd->str, ' ');
////	len =
//	i = 0;
//	while (cmd->str[i] == ' ')
//		i++;
//	while (cmd->str[i])
//	{
//		while (cmd->str[i] == )
//	}
//	return (0);
//}

static char	*ft_cpystr(char *src, int len)
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
	if ((ft_strlen(res) + 1) == len || ft_isspace(line, i) || !res)//коммент от Дашули:
								//здесь нужно убрать условие !res 
	{
		return (3); // to check if waiting mode is needed
	}
//	if ((ft_strlen(cmd->left_pipe) + 1) == len || ft_isspace(line, i) || !cmd->left_pipe)
//	{
//		return (3); // to check if waiting mode is needed
//	}
	cmd->left_pipe = res;
//	printf("%s\n", res);
	// free(res);
	line = ft_substr(line, i + 1, len - i);
	return (1);
}


int is_cmd(t_cmd *cmd)
{
	/* тут, понятное дело, все написано на соплях. нет форков итд
	похоже именно поэтому после выполнения ./minishell сразу выходит

	кроме того я не смогла победить компуктер и включить t_data в свою функцию
	поэтому я продублировала char **envp в свою структуру,
	что конечно нужно будет переделать 
	пока тут работает только команда ls, 
	потому что я вручную передаю ей флаги с помощью char *cmd_args что довольно тупо)))
	а с другими командами вообще подвисает
	такие дела*/
    char	*tmp;
    char	*c;
	int		i;

	i = 0;

    while (cmd->cmd_paths[i])
    {
        tmp = ft_strjoin(cmd->cmd_paths[i], "/");
        c = ft_strjoin(tmp, cmd->c_list->val);// put splitted word or command
        free(tmp);
        if (access(c, 0) == 0)
		{
			cmd->exec_list = new_list(c, 0);
			free(c);
            return (1);
		}
		free(c);
		i++;
    }
    return (0);
}

void	exec_simple(t_cmd *cmd)
{
	char	**c_args;
	int		i;
	int		ind;
	t_env	*tmp;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return ;
	}
	else if (pid == 0)
	{
		i = 0;
		tmp = cmd->c_list;
		while(tmp)
		{
			i++;
			tmp = tmp->next;
		}
		c_args = malloc(sizeof(char*) * i);
		if (!c_args)
		{
			ft_putstr_fd("Malloc error\n", 2);
			exit(EXIT_FAILURE);
		}
		cmd->c_list = cmd->c_list->next;
		ind = 0;
		while (--i > 0)
		{
			// c_args[ind] = malloc(sizeof(char) *ft_strlen(cmd->c_list->val));//может не надо?)//если надо, то добавить if (!c_args[ind])
			c_args[ind] = cmd->c_list->val;//вроде так работает, ноя подумала, что может быть можно массив войд пойнтеров сделать?)
			// printf("%s\n", c_args[ind]);
			ind++;
			// printf("%i\n", i);
			// printf("%d %s\n", cmd->c_list->ind, cmd->c_list->val);
			cmd->c_list = cmd->c_list->next;
		}
		if (execve(cmd->exec_list->val, c_args, cmd->env) < 0) //ФОРКИ! А то выходит
		{
			perror("execve");
			// ft_putstr_fd("Execve error\n", 2);
			// exit(EXIT_FAILURE);
		}
	}
	waitpid(pid, 0, 0);//set exitstaus
}
