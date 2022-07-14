

#include "env.h"

int ft_isspace(char *s, int i)
{
	int len;
	int	tmp;

	len = 0;
	tmp = i;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
	{
		len++;
		i++;
	}
	// printf("%d\n", len);
	if (len == ft_strlen(s) - tmp)
		return (1);
	return (0);
}

// int main()
// {
// 	char *s = "123     ";
// 	int i = 3;
// 	// ft_isspace(s,i);
// 	printf("%d\n", ft_isspace(s,i));
// }
