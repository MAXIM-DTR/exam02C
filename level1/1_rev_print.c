/*
** rev_print - affiche une string à l'envers, suivi d'un \n
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
			i++;
		i--; // car il pointe sur le caractere nul
		while (i >= 0)
		{
			write (1, &argv[1][i], 1);
			i--;
		}
	}
	write (1, "\n", 1);
}
