/* wdmatch - verifie si s1 est cache dans s2
** Chaque char de s1 doit apparaitre dans s2 dans le meme ordre
** (pas forcement consecutifs)
** Si oui -> afficher s1, sinon -> rien. Toujours afficher newline */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		/* Avancer dans les deux strings en meme temps */
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;  /* Char de s1 trouve dans s2 -> passer au suivant */
			j++;      /* Toujours avancer dans s2 */
		}
		/* Si on a trouve tous les chars de s1 (i a atteint la fin) */
		if (!argv[1][i])
		{
			i = 0;
			while (argv[1][i])
			{
				write(1, &argv[1][i], 1);
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
