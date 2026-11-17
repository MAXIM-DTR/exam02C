/*
** rostring - rotation d'une string: deplace le premier mot a la fin
** Ex: "lorem ipsum dolor" -> "ipsum dolor lorem"
** Ex: "   first   second  " -> "second first" (espaces geres)
** Ex: "abc   " -> "abc" (un seul mot: reste seul)
**
** Algorithme:
** 1. Sauter les espaces initiaux -> trouver le debut du premier mot (w1s)
** 2. Avancer jusqu'a la fin du premier mot (i = apres le premier mot)
** 3. Appeler print_words depuis i (affiche les mots RESTANTS)
** 4. Si des mots ont ete affiches: ajouter un espace avant le premier mot
** 5. Afficher le premier mot (str[w1s..i-1])
*/
#include <unistd.h>

/*
** print_words - affiche tous les mots de s a partir de l'index start
** Gere les espaces superflus (un seul espace entre les mots)
** Retourne 1 si au moins un mot a ete affiche, 0 sinon
** (ce retour sert a savoir si on doit ajouter un espace avant le 1er mot)
*/
int	print_words(char *s, int start)
{
	int	i;      /* Index courant dans s, commence a start */
	int	first;  /* Flag: 1 au debut, passe a 0 apres le premier mot affiche */

	i = start;
	first = 1;  /* Pas encore affiche de mot */
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\t')  /* Sauter les separateurs */
			i++;
		/* Si on a un char ET ce n'est pas le premier mot: ajouter un espace */
		if (s[i] && !first)
			write(1, " ", 1);
		/* Afficher les chars du mot courant */
		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			first = 0;  /* On a affiche au moins un char */
			i++;
		}
	}
	return (!first);  /* 1 si au moins un mot affiche (first est passe a 0) */
}

/*
** write_word - affiche s[start..end-1] (le premier mot dans notre cas)
*/
void	write_word(char *s, int start, int end)
{
	while (start < end)
		write(1, &s[start++], 1);
}

int	main(int argc, char **argv)
{
	int	i;    /* Index qui avancera jusqu'a la fin du premier mot */
	int	w1s;  /* "word 1 start" = debut du premier mot */

	if (argc >= 2)
	{
		i = 0;
		/* Sauter les espaces initiaux */
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		w1s = i;  /* Marquer le debut du premier mot */
		/* Avancer jusqu'a la fin du premier mot */
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i++;
		/* Afficher les mots 2, 3, 4... (a partir de i, apres le premier mot) */
		if (print_words(argv[1], i))  /* Si au moins un mot apres le premier */
			write(1, " ", 1);         /* Ajouter un espace avant le premier mot */
		write_word(argv[1], w1s, i);  /* Afficher le premier mot en dernier */
	}
	write(1, "\n", 1);
	return (0);
}
