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

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			write(1, "_", 1);
			argv[1][i] += 32;
		}
		write(1, &argv[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
