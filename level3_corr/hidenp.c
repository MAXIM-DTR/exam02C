/*
** hidenp - verifie si s1 est "cache" dans s2 (meme logique que wdmatch)
** s1 est cache dans s2 si on peut trouver chaque char de s1 dans s2,
** dans le meme ordre (pas forcemment consecutifs)
** La string vide est cachee dans n'importe quelle string
**
** Affiche "1\n" si cache, "0\n" si non, "\n" si argc != 3
**
** Algorithme: deux pointeurs i (dans s1) et j (dans s2)
** - On avance j a chaque iteration
** - On avance i seulement quand s1[i] == s2[j] (char trouve)
** - A la fin: si s1[i] == '\0' -> tous les chars de s1 ont ete trouves
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;  /* Index dans s1 (argv[1]): avance quand un char est trouve */
	int	j;  /* Index dans s2 (argv[2]): avance a chaque etape */

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;  /* Char de s1 trouve dans s2: passer au suivant dans s1 */
			j++;      /* Toujours avancer dans s2 */
		}
		if (argv[1][i] == '\0')    /* i a atteint la fin de s1 -> tous trouves */
			write(1, "1\n", 2);
		else
			write(1, "0\n", 2);    /* Il manque au moins un char de s1 */
	}
	else
		write(1, "\n", 1);
	return (0);
}
