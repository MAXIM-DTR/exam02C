/* epur_str - supprime espaces superflus
** Methode: traiter mot par mot
** - Sauter les separateurs
** - Si ce n'est pas le premier mot, afficher un espace avant
** - Afficher le mot complet
** RESULTAT: pas d'espace en debut/fin, un seul espace entre mots */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (argv[1][i])
		{
			/* Sauter les espaces et tabs */
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			/* Si il y a un mot ET ce n'est pas le premier -> espace avant */
			if (argv[1][i] && !first)
				write(1, " ", 1);
			/* Afficher le mot */
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				first = 0;
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
