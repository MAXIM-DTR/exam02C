/*
** snake_to_camel - convertit snake_case en lowerCamelCase
** here_is_a_snake_case_word → hereIsASnakeCaseWord
** Si argc != 2 : afficher seulement \n
** Allowed: malloc, free, realloc, write
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '_')      // underscore trouvé
		{
			i++;                    // on saute l'underscore
			if (argv[1][i])
			{
				c = argv[1][i] - 32; // - 32 = passe en MAJUSCULE
				write(1, &c, 1);
			}
		}
		else
			write(1, &argv[1][i], 1); // char normal → on écrit direct
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
