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

	// Si pas exactement 1 argument → juste un \n
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i]) // parcourt chaque caractère du mot
	{
		if (argv[1][i] == '_') // on trouve un underscore
		{
			i++;                    // on saute l'underscore
			if (argv[1][i])         // si y'a un char après
			{
				c = argv[1][i] - 32; // on met en MAJUSCULE (diff = 32)
				write(1, &c, 1);     // on écrit la majuscule à la place du _x
			}
		}
		else
			write(1, &argv[1][i], 1); // caractère normal → on écrit direct
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
