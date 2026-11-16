/* rev_wstr - affiche les mots d'une chaîne en ordre inverse
** Prototype : int main(int argc, char **argv)
** Usage : ./rev_wstr "une phrase quelconque"
**
** Exemples :
**   ./rev_wstr "Hello World"       → "World Hello"
**   ./rev_wstr "  une  phrase  "   → "phrase une"
**   ./rev_wstr                     → (newline)
**
** Algorithme :
**   - On part de la fin de la chaîne
**   - On saute les espaces/tabs
**   - On trouve la fin du mot, puis le début
**   - On affiche le mot, puis un espace s'il reste des mots
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;
	int	j;

	if (argc == 2)
	{
		/* Aller à la fin de la chaîne */
		i = 0;
		while (argv[1][i])
			i++;
		i--;
		while (i >= 0)
		{
			/* Sauter les espaces/tabs de droite */
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			end = i; /* Marquer la fin du mot */
			/* Reculer jusqu'au début du mot */
			while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			j = i + 1; /* Début du mot */
			/* Afficher le mot caractère par caractère */
			while (j <= end)
				write(1, &argv[1][j++], 1);
			/* Ajouter un espace si ce n'est pas le dernier mot */
			if (i >= 0 && end >= 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
