/*
** rotone - décale chaque lettre d'une position dans l'alphabet
** 'a'→'b', 'z'→'a', 'A'→'B', 'Z'→'A'. Non-lettres inchangés. Suivi \n.
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
			if ((argv[1][i] >= 'a' && argv[1][i] < 'z') || (argv[1][i] >= 'A' && argv[1][i] < 'Z'))
			{
				argv[1][i] = argv[1][i] + 1;
				write (1, &argv[1][i], 1);
			}
		// BUG 2: doit être "else if" — 'y' devient 'z' dans le 1er if, puis ce 2e if
		// détecte 'z' et écrit encore → 'y' produit 2 caractères en sortie
		// BUG 3: pas de else final → les non-lettres disparaissent de la sortie
			else if (argv[1][i] == 'Z' || argv[1][i] == 'z')
			{
				argv[1][i] = argv[1][i] - 25;
				write (1, &argv[1][i], 1);
			}
			else 
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
