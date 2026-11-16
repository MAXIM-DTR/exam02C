/* hidenp - verifie si s1 est cache dans s2
** Chaque char de s1 doit apparaitre dans s2 dans le meme ordre
** Affiche 1 si oui, 0 sinon */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;
	char	result;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;  /* Char trouve -> avancer dans s1 */
			j++;      /* Toujours avancer dans s2 */
		}
		if (!argv[1][i])  /* Tous les chars de s1 trouves */
			result = '1';
		else
			result = '0';
		write(1, &result, 1);
	}
	write(1, "\n", 1);
	return (0);
}
