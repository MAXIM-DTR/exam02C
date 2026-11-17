/*
** rev_print - affiche une string a l'envers
** Ex: "hello" -> "olleh"
**
** Algorithme en 2 phases:
** Phase 1: trouver la fin de la string (position du '\0')
**          puis reculer d'un cran pour pointer sur le dernier char
** Phase 2: afficher chaque char en reculant jusqu'au debut (i >= 0)
*/
#include <unistd.h>

void	rev_print(char *str)
{
	int	i;  /* Index: commence a 0, puis on le deplace jusqu'a la fin */

	i = 0;
	/* Phase 1: avancer i jusqu'au '\0' */
	while (str[i] != 0)
		i++;
	/* Maintenant str[i] == '\0'. On recule d'un cran pour pointer sur le dernier char */
	i--;
	/* Phase 2: afficher de droite a gauche */
	while (i >= 0)
	{
		write(1, &str[i], 1);  /* Afficher le char a la position i */
		i--;                    /* Reculer vers le debut */
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}
