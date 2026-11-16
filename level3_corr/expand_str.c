/* expand_str - remplace chaque espace par 10 espaces */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
			{
				j = 0;
				while (j < 10)  /* Afficher 10 espaces a la place d'un */
				{
					write(1, " ", 1);
					j++;
				}
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
