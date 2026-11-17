/*
** last_word - affiche le dernier mot d'une string
** Un "mot" = chars non-separateurs, delimite par espaces/tabs ou debut/fin
**
** Algorithme en 3 etapes depuis la FIN:
** Etape 1: Reculer pour sauter les espaces/tabs de FIN de string
**          (il peut y en avoir plusieurs a la fin)
** Etape 2: Marquer 'end' = position du dernier char du mot
**          Continuer a reculer jusqu'au prochain separateur ou debut
** Etape 3: 'start' = i + 1 = premiere position du mot
**          Afficher de start a end inclus
*/
#include <unistd.h>

void	last_word(char *str)
{
	int	i;      /* Index qui se deplace depuis la fin vers le debut */
	int	start;  /* Position du premier char du dernier mot */
	int	end;    /* Position du dernier char du dernier mot */

	i = 0;
	while (str[i])  /* Aller a la fin de la string */
		i++;
	i--;  /* Reculer d'un cran pour pointer sur le dernier char */
	/* Etape 1: sauter les espaces/tabs de fin */
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	end = i;  /* i pointe maintenant sur le dernier char du mot */
	/* Etape 2: reculer jusqu'au separateur ou debut de string */
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	/* i est maintenant sur le separateur avant le mot (ou -1 si debut de string) */
	start = i + 1;  /* Le mot commence a la position apres le separateur */
	/* Etape 3: afficher de start a end */
	while (start <= end)
		write(1, &str[start++], 1);  /* Afficher et incrementer start */
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
