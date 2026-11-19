/*
** camel_to_snake - convertit lowerCamelCase en snake_case
** hereIsACamelCaseWord → here_is_a_camel_case_word
** Si argc != 2 : afficher seulement \n
** Allowed: malloc, realloc, write
*/

#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	// Si pas exactement 1 argument → juste un \n
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i]) // parcourt chaque caractère du mot
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z') // c'est une majuscule
		{
			write(1, "_", 1);       // on écrit d'abord un underscore
			argv[1][i] += 32;       // on convertit en minuscule (A=65, a=97, diff=32)
		}
		write(1, &argv[1][i], 1);   // on écrit le caractère (minuscule ou déjà petit)
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
