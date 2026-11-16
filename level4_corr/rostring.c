/* rostring - deplace le premier mot a la fin
** "hello world foo" -> "world foo hello"
** Methode:
** 1. Trouver le premier mot (debut et fin)
** 2. Afficher le reste de la string
** 3. Afficher un espace + le premier mot */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	first_start;
	int	first_end;
	int	i;

	if (argc == 2)
	{
		/* Sauter les espaces du debut */
		first_start = 0;
		while (argv[1][first_start] == ' ')
			first_start++;
		/* Trouver la fin du premier mot */
		first_end = first_start;
		while (argv[1][first_end] && argv[1][first_end] != ' ')
			first_end++;
		/* Trouver le debut du reste */
		i = first_end;
		while (argv[1][i] == ' ')
			i++;
		/* Afficher le reste puis le premier mot */
		if (argv[1][i])
		{
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
			write(1, " ", 1);
		}
		/* Afficher le premier mot */
		while (first_start < first_end)
		{
			write(1, &argv[1][first_start], 1);
			first_start++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
