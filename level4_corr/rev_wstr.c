/*
** rev_wstr - affiche les mots d'une string en ordre inverse
** Ex: "Hello World foo" -> "foo World Hello"
** IMPORTANT: pas d'espaces superflus au debut/fin selon le sujet
** (le sujet garantit qu'il n'y a pas d'espaces en debut/fin dans les tests)
**
** Algorithme: partir de la FIN de la string
** Pour chaque mot (en allant de droite a gauche):
** 1. Sauter les espaces/tabs de droite
** 2. Marquer 'end' = position du dernier char du mot
** 3. Reculer jusqu'au separateur (trouver le debut du mot)
** 4. Afficher le mot (de i+1 a end inclus)
** 5. Si i >= 0 (il reste des mots): afficher un espace
*/
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;    /* Index principal: commence a la fin, recule vers le debut */
	int	end;  /* Position du dernier char du mot courant */
	int	j;    /* Index temporaire pour afficher le mot (de i+1 a end) */

	if (argc == 2)
	{
		/* Aller a la fin de la string */
		i = 0;
		while (argv[1][i])
			i++;
		i--;  /* Pointer sur le dernier char */
		while (i >= 0)
		{
			/* Sauter les espaces/tabs a droite du mot courant */
			while (i >= 0 && (argv[1][i] == ' ' || argv[1][i] == '\t'))
				i--;
			end = i;  /* i est maintenant sur le dernier char du mot */
			/* Reculer jusqu'au separateur (trouver le debut du mot) */
			while (i >= 0 && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--;
			/* i est maintenant sur le separateur (ou -1 si debut de string) */
			j = i + 1;  /* j pointe sur le premier char du mot */
			while (j <= end)
				write(1, &argv[1][j++], 1);  /* Afficher le mot */
			/* Si i >= 0: il reste encore des mots a gauche -> ajouter un espace */
			if (i >= 0 && end >= 0)
				write(1, " ", 1);
		}
	}
	write(1, "\n", 1);
	return (0);
}
