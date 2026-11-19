/*
** wdmatch - vérifie si s1 peut être écrit avec les chars de s2 (dans l'ordre)
** Si oui : afficher s1 + \n, sinon : afficher \n
** Si argc != 3 : afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	j = 0;
	while (argv[1][i] && argv[2][j])
	{
		if (argv[1][i] == argv[2][j])
			i++;
		j++;
	}
	if (!argv[1][i])
	{
		j = 0;
		while (argv[1][j])
			write(1, &argv[1][j++], 1);
	}
	write(1, "\n", 1);
	return (0);
}
