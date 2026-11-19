/*
** search_and_replace - remplace toutes les occurrences d'un char par un autre
** argv[1]: string | argv[2]: char à chercher | argv[3]: char de remplacement
** Si argc != 4: afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int i;
	if (argc == 4 && !argv[2][1] && !argv[3][1])
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == argv[2][0])
				write (1, &argv[3][0], 1);
			else 
				write (1, &argv[1][i], 1);
			i++;
		}
	}
	write (1, "\n", 1);
}
