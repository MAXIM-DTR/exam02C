/*
** alpha_mirror - remplace chaque lettre par son opposé alphabétique
** 'a'→'z', 'Z'→'A', 'd'→'w', 'M'→'N' (casse inchangée)
** Si argc != 2 : afficher seulement \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 2)              // pas exactement 1 argument → \n et stop
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		// opposé alphabétique : 'a'+'z' = 219, donc 219 - 'a' = 'z' et vice-versa
		if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			argv[1][i] = 'a' + 'z' - argv[1][i];
		else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			argv[1][i] = 'A' + 'Z' - argv[1][i];
		write(1, &argv[1][i], 1);  // on modifie argv en place → pas besoin de var tmp
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
