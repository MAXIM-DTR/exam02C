/* ft_split - decoupe une string par des separateurs
** Retourne un tableau de strings NULL-termine (alloue avec malloc)
** Chaque char de charset est un separateur possible */
#include <unistd.h>
#include <stdlib.h>

/* Verifie si c est un separateur */
int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

/* Compte le nombre de mots */
int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (!is_sep(*str, charset) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (is_sep(*str, charset))
			in_word = 0;
		str++;
	}
	return (count);
}

/* Copie len chars depuis start dans une nouvelle string */
char	*copy_word(char *start, int len)
{
	char	*word;
	int		i;

	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		nb_words;
	int		i;
	int		j;
	int		wlen;

	nb_words = count_words(str, charset);
	result = malloc((nb_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < nb_words)
	{
		/* Sauter les separateurs */
		while (str[i] && is_sep(str[i], charset))
			i++;
		/* Calculer la longueur du mot */
		wlen = 0;
		while (str[i + wlen] && !is_sep(str[i + wlen], charset))
			wlen++;
		result[j] = copy_word(str + i, wlen);
		i += wlen;
		j++;
	}
	result[j] = NULL;  /* Terminer le tableau par NULL */
	return (result);
}
