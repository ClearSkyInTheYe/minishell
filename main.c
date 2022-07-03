/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:38:16 by chfederi          #+#    #+#             */
/*   Updated: 2022/06/28 23:38:18 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_parser(char *s, t_data *d)
{
	char	*a;

	if (ft_strcmp(s, "exit") == 0)
	{
//		printf("asd");
		d->ex = 2;
	}
}

//t_data	*ft_init(t_data *d)
//{
//	d = malloc(sizeof (t_data));
//	if (!d)
//		exit(3);
//	d->ex = 1;
//	return (d);
//}

int	main(int argc, char **argv, char **env)
{
	char	*s;
	t_data	d;
	t_env	*e;

//	d = ft_init(d);
	d.ex = 1;
//	while (d.ex == 1)
//	{
//		s = readline(argv[1]);
////		printf("%s\n", s);
//		ft_parser(s, &d);
//	}
	e = init_env(&d, e, env);
//	printf("%i\n", env_len(env));
//	printf("q%s\n", env[1]);
	printf("1%s\n", e->en);
	printf("2%s\n", e->next->en);
	printf("3%s\n", e->next->next->en);
	exit(3);
}
