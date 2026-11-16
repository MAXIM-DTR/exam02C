/* rostring - déplace le premier mot à la fin
** Prototype : int main(int argc, char **argv)
** Usage : ./rostring "une phrase quelconque"
**
** Exemples :
**   ./rostring "lorem ipsum dolor sit amet" → "ipsum dolor sit amet lorem"
**   ./rostring "   lorem   ipsum   "        → "ipsum lorem"
**   ./rostring                              → (newline)
**
** Algorithme :
**   1. Identifier le premier mot (w1s = début, i = fin)
**   2. Afficher tous les mots restants (à partir de i)
**   3. Si des mots ont été affichés, ajouter un espace
**   4. Afficher le premier mot
*/

#include <unistd.h>

/* Affiche les mots de s à partir de start, avec espaces entre eux.
** Retourne 1 si au moins un mot a été affiché, 0 sinon. */
int	print_words(char *s, int start)
{
	int	i;
	int	first;

	i = start;
	first = 1;
	while (s[i])
	{
		/* Sauter les espaces/tabs */
		while (s[i] == ' ' || s[i] == '\t')
			i++;
		/* Ajouter un espace entre les mots (pas avant le premier) */
		if (s[i] && !first)
			write(1, " ", 1);
		/* Afficher les caractères du mot */
		while (s[i] && s[i] != ' ' && s[i] != '\t')
		{
			write(1, &s[i], 1);
			first = 0;
			i++;
		}
	}
	return (!first); /* 1 si au moins un mot affiché */
}

/* Affiche s[start..end-1] */
void	write_word(char *s, int start, int end)
{
	while (start < end)
		write(1, &s[start++], 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	w1s;

	if (argc >= 2)
	{
		i = 0;
		/* Sauter les espaces au début */
		while (argv[1][i] == ' ' || argv[1][i] == '\t')
			i++;
		w1s = i; /* Début du premier mot */
		/* Avancer jusqu'à la fin du premier mot */
		while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
			i++;
		/* Afficher le reste (mots 2, 3, ...) */
		if (print_words(argv[1], i))
			write(1, " ", 1); /* Espace avant le premier mot déplacé */
		/* Afficher le premier mot en dernier */
		write_word(argv[1], w1s, i);
	}
	write(1, "\n", 1);
	return (0);
}
