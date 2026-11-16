/* wdmatch - verifie si s1 est cache dans s2
** Avancer i dans s1 seulement quand on trouve s1[i] dans s2
** A la fin, si s1[i] == '\0' -> tous les chars trouves -> afficher s1 */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;
			j++;
		}
		if (argv[1][i] == '\0')
		{
			i = 0;
			while (argv[1][i])
				write(1, &argv[1][i++], 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
