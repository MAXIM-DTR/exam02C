/* snake_to_camel - snake_case -> camelCase
** Quand on rencontre '_': sauter le _ et mettre
** la lettre suivante en majuscule (-32 en ASCII) */
#include <unistd.h>

void	snake_to_camel(char *str)
{
	char	c;
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_' && str[i + 1] != '\0')
		{
			c = str[i + 1] - 32;  /* Lettre apres _ en majuscule */
			write(1, &c, 1);
			i += 2;               /* Sauter le _ ET la lettre */
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1, "\n", 1);
	return (0);
}
