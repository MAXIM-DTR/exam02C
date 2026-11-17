/*
** wdmatch - verifie si s1 peut etre ecrit avec les chars de s2 (dans l'ordre)
** Si oui: afficher s1 + newline. Si non: afficher seulement newline.
**
** Technique des deux pointeurs:
** - i parcourt s1 (le mot cherche)
** - j parcourt s2 (la source)
** - Pour chaque char de s1[i], on avance dans s2 jusqu'a le trouver
** - Si on trouve s1[i] dans s2: on avance i ET j
** - Si on ne trouve pas: on avance seulement j
** A la fin:
** - Si i == longueur de s1 (s1[i] == '\0'): tous les chars ont ete trouves -> afficher s1
** - Sinon: il manque des chars -> afficher rien (juste \n)
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;  /* Index dans s1 (argv[1]): avance quand on trouve un match */
	int	j;  /* Index dans s2 (argv[2]): avance a chaque iteration */

	if (argc == 3)
	{
		i = 0;
		j = 0;
		/* Parcourir s2 tant qu'il reste des chars dans s1 ET dans s2 */
		while (argv[1][i] && argv[2][j])
		{
			if (argv[1][i] == argv[2][j])
				i++;  /* Match trouve: passer au char suivant de s1 */
			j++;      /* Toujours avancer dans s2 */
		}
		/* Si s1[i] == '\0': on a trouve tous les chars de s1 dans s2 -> succes */
		if (argv[1][i] == '\0')
		{
			i = 0;
			while (argv[1][i])
				write(1, &argv[1][i++], 1);  /* Afficher s1 */
		}
	}
	write(1, "\n", 1);
	return (0);
}
