/* repeatalpha - repete chaque lettre N fois
** N = rang dans l'alphabet (a=1, b=2, ..., z=26)
** Les non-lettres sont affiches normalement
** Ex: "ab" -> "abb" (a=1 fois, b=2 fois) */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	int	rank;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
				rank = argv[1][i] - 'a' + 1;  /* a=1, b=2 ... */
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
				rank = argv[1][i] - 'A' + 1;  /* A=1, B=2 ... */
			else
				rank = -1;  /* Pas une lettre */
			if (rank == -1)
				write(1, &argv[1][i], 1);
			else
			{
				j = 0;
				while (j < rank)  /* Afficher 'rank' fois */
				{
					write(1, &argv[1][i], 1);
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
