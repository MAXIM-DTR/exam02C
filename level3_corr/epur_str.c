/*
** epur_str - nettoie les espaces superflus d'une string
** Resultat: exactement 1 espace entre chaque mot, pas d'espaces au debut/fin
**
** Algorithme "mot par mot":
** - Variable 'first': vaut 1 au debut, passe a 0 apres le premier mot
**   Sert a ne PAS mettre d'espace avant le tout premier mot
** - Pour chaque mot: sauter les separateurs, puis afficher le mot
** - Avant chaque mot (sauf le 1er): afficher 1 espace
**
** La combinaison de 'first' et de la detection de mot garantit:
** - Pas d'espace au debut (first=1 au premier mot)
** - Pas d'espace a la fin (on affiche l'espace AVANT le mot, pas APRES)
** - Exactement 1 espace entre les mots
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;      /* Index courant dans argv[1] */
	int	first;  /* Flag: 1 = on n'a pas encore affiche de mot, 0 = deja affiche */

	if (argc == 2)
	{
		i = 0;
		first = 1;  /* Au debut, aucun mot affiche */
		while (argv[1][i])
		{
			/* Sauter tous les espaces et tabs */
			while (argv[1][i] == ' ' || argv[1][i] == '\t')
				i++;
			/* S'il reste un char ET ce n'est pas le premier mot: afficher un espace */
			if (argv[1][i] && !first)
				write(1, " ", 1);
			/* Afficher les chars du mot (jusqu'au prochain separateur) */
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			{
				write(1, &argv[1][i], 1);
				first = 0;  /* On vient d'afficher au moins un char -> plus "premier" */
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
