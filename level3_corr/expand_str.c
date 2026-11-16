/* expand_str - comme epur_str mais 3 espaces entre chaque mot
** (au lieu d'un seul espace dans epur_str)
** Meme logique: traitement mot par mot */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	first;

	if (argc == 2)
	{
		i = 0;
		first = 1;
		while (argv[1][i])
		{
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
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
