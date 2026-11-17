/*
** expand_str - comme epur_str mais avec 3 espaces entre les mots (pas 1)
** La seule difference avec epur_str: write(1, "   ", 3) au lieu de write(1, " ", 1)
**
** Rappel de l'algorithme:
** - 'first': evite de mettre 3 espaces AVANT le premier mot
** - Sauter separateurs, si mot et pas premier -> 3 espaces, puis le mot
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;      /* Index courant dans argv[1] */
	int	first;  /* Flag: 0 apres le premier mot affiche */

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			/* Mot trouve ET pas le premier -> afficher 3 espaces comme separateur */
			if (argv[1][i] && !first)
				write(1, "   ", 3);  /* 3 espaces entre les mots */
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				first = 0;
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
