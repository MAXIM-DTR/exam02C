/* rev_print - affiche une string en sens inverse
** On calcule la longueur puis on affiche de la fin vers le debut */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		/* Trouver la fin de la string */
		while (argv[1][i])
			i++;
		/* Afficher en remontant */
		while (i > 0)
		{
			i--;
			write(1, &argv[1][i], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
