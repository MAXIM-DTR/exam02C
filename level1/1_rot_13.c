/*
** rot_13 - chiffrement ROT13: décale chaque lettre de 13 positions
** Casse préservée. Non-lettres affichés inchangés. Suivi d'un \n.
** Si argc != 2: afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i;
		i = 0;
		while (argv[1][i])
		{
			if ((argv[1][i] >= 'a' && argv[1][i] <= 'm') || (argv[1][i] >= 'A' && argv[1][i] <= 'M'))
			{
				argv[1][i] = argv[1][i] + 13;
				write (1, &argv[1][i], 1);
			}
			else if ((argv[1][i] >= 'N' && argv[1][i] <= 'Z') || (argv[1][i] >= 'n' && argv[1][i] <= 'z'))
			{
				argv[1][i] = argv[1][i] - 13;
				write (1, &argv[1][i], 1);
			}
			// BUG: pas de else ici — les non-lettres (espaces, chiffres, ponctuation)
			// ne sont jamais écrits et disparaissent de la sortie
			// FIX: ajouter else { write(1, &argv[1][i], 1); }
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
