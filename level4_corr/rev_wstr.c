/* rev_wstr - affiche les mots en ordre inverse
** "hello world foo" -> "foo world hello"
** Methode: partir de la fin, trouver chaque mot en reculant */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;
	int	start;
	int	first_word;

	if (argc == 2)
	{
		/* Trouver la fin de la string */
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		first_word = 1;
		while (i >= 0)
		{
			/* Reculer pour sauter les espaces */
			while (i >= 0 && argv[1][i] == ' ')
				i--;
			end = i + 1;
			/* Reculer pour trouver le debut du mot */
			while (i >= 0 && argv[1][i] != ' ')
				i--;
			start = i + 1;
			if (start < end)
			{
				if (!first_word)
					write(1, " ", 1);
				/* Afficher le mot */
				while (start < end)
				{
					write(1, &argv[1][start], 1);
					start++;
				}
				first_word = 0;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
