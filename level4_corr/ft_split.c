/*
** ft_split - decoupe une string en tableau de mots (separes par espace/tab/newline)
** Retourne un tableau de strings NULL-termine (alloue avec malloc)
** ATTENTION: pas de parametre charset, les separateurs sont HARDCODES
** Separateurs: ' ' (espace), '\t' (tabulation), '\n' (saut de ligne)
**
** Ex: ft_split("  hello   world  ") -> ["hello", "world", NULL]
**
** Etapes:
** 1. is_sep: helper pour reconnaitre un separateur
** 2. count_words: compter le nombre de mots (pour allouer le bon tableau)
** 3. word_dup: allouer et copier un mot (str[start..end-1])
** 4. ft_split: allouer le tableau, puis remplir avec word_dup
*/
#include <stdlib.h>

/* is_sep - retourne 1 si c est un separateur, 0 sinon */
int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/*
** count_words - compte le nombre de mots dans str
** Un mot = sequence de non-separateurs entre deux separateurs
** On compte en detectant les transitions separateur->non-separateur
*/
int	count_words(char *str)
{
	int	count;  /* Nombre de mots trouves */
	int	i;      /* Index courant */

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))  /* Sauter les separateurs */
			i++;
		if (str[i] && !is_sep(str[i]))    /* On tombe sur un mot */
		{
			count++;
			while (str[i] && !is_sep(str[i]))  /* Passer tout le mot */
				i++;
		}
	}
	return (count);
}

/*
** word_dup - alloue et retourne la copie de str[start..end-1]
** end-start = longueur du mot, +1 pour le '\0'
*/
char	*word_dup(char *str, int start, int end)
{
	char	*word;  /* Le mot alloue */
	int		i;      /* Index dans word (commence a 0) */

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
		word[i++] = str[start++];  /* Copier les chars du mot */
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**split;  /* Le tableau de strings alloue */
	int		i;        /* Index dans str source */
	int		j;        /* Index dans split (numero du mot courant) */
	int		start;    /* Position du debut du mot courant dans str */

	/* Allouer le tableau: count_words+1 cases (+1 pour le NULL final) */
	split = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i] && is_sep(str[i]))  /* Sauter les separateurs */
			i++;
		start = i;  /* Marquer le debut du mot */
		while (str[i] && !is_sep(str[i]))  /* Avancer jusqu'a la fin du mot */
			i++;
		if (i > start)  /* i > start signifie qu'on a avance = on a trouve un mot */
			split[j++] = word_dup(str, start, i);
	}
	split[j] = NULL;  /* Terminer le tableau avec un pointeur NULL */
	return (split);
}
