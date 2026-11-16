/* first_word - affiche le premier mot d'une string
** On saute les espaces du debut, puis on affiche
** jusqu'au prochain espace ou fin de string */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		/* Sauter les espaces et tabulations au debut */
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		/* Afficher les chars jusqu'au prochain separateur */
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
