/* last_word - affiche le dernier mot d'une string
** 1. Reculer pour sauter les espaces trailing
** 2. Marquer la fin du mot
** 3. Reculer pour trouver le debut du mot
** 4. Afficher */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
			i++;
		/* Sauter les espaces de fin */
		while (i > 0 && argv[1][i - 1] == ' ')
			i--;
		end = i;
		/* Reculer jusqu'au debut du dernier mot */
		while (i > 0 && argv[1][i - 1] != ' ')
			i--;
		/* Afficher le mot */
		while (i < end)
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
