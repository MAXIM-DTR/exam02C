/*
** repeatalpha - répète chaque lettre selon sa position dans l'alphabet
** 'a'/'A' → 1 fois, 'b'/'B' → 2 fois, ..., 'z'/'Z' → 26 fois
** Non-lettres affichés tels quels (1 fois). Suivi d'un \n.
** Si argc != 2: afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	int repeat; // combien de fois on repete la lettre 
	if (argc == 2)
	{
		i = 0;
		repeat = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				repeat = argv[1][i] + 1 - 'A'; // calcule pour le nb de repeat
			else if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				repeat = argv[1][i] + 1 - 'a';
			else 
				repeat = 1; // si y en a pas plusieurs donc jsute unefois la letrre
			while (repeat > 0) // donc tant qu on a pas repeter la lettre le bon nb de fosi 
			{
				write (1, &argv[1][i], 1);
				repeat--; // decremente
			}
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
