/*
** first_word - affiche le premier mot d'une string passée en argument
** Séparateurs: espaces et \t\n\v\f\r (chars 9 à 13)
** Si argc != 2 ou pas de mot: afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	if (argc == 2)
	{
		i = 0;
		// pas oublier les separteur 
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{ 
			write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
	return (0);
}
