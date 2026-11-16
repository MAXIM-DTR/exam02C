/* ft_split - découpe une chaîne en mots (séparateurs : espace, tab, newline)
** Prototype : char **ft_split(char *str);
** - str : la chaîne à découper
** Retourne un tableau de chaînes (NULL-terminé), alloué avec malloc.
**
** Exemple :
**   ft_split("  bonjour  monde  ") → ["bonjour", "monde", NULL]
**
** Séparateurs : ' ' (espace), '\t' (tabulation), '\n' (saut de ligne)
** ATTENTION : pas de paramètre charset ! Séparateurs hardcodés.
*/

#include <stdlib.h>

/* Vérifie si un caractère est un séparateur */
int	is_sep(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/* Compte le nombre de mots dans la chaîne */
int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		/* Sauter les séparateurs */
		while (str[i] && is_sep(str[i]))
			i++;
		/* Si on trouve un mot, incrémenter */
		if (str[i] && !is_sep(str[i]))
		{
			count++;
			while (str[i] && !is_sep(str[i]))
				i++;
		}
	}
	return (count);
}

/* Duplique un mot de str[start..end-1] */
char	*word_dup(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * (end - start + 1));
	i = 0;
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str)
{
	char	**split;
	int		i;
	int		j;
	int		start;

	split = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		/* Sauter les séparateurs */
		while (str[i] && is_sep(str[i]))
			i++;
		start = i;
		/* Avancer jusqu'au prochain séparateur */
		while (str[i] && !is_sep(str[i]))
			i++;
		/* Si on a avancé, c'est un mot */
		if (i > start)
			split[j++] = word_dup(str, start, i);
	}
	split[j] = NULL; /* Terminer le tableau avec NULL */
	return (split);
}
