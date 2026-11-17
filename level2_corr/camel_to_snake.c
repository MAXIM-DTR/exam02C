/*
** camel_to_snake - convertit lowerCamelCase en snake_case
** Ex: hereIsACamelCaseWord -> here_is_a_camel_case_word
**
** Principe: chaque Majuscule devient '_' + minuscule correspondante
** SAUF si c'est le premier char (pas de '_' au debut)
**
** Pourquoi malloc?
** La string resultante est plus longue que l'originale:
** chaque majuscule ajoute 1 char (le '_') sauf la 1ere
** -> Besoin d'allouer de la memoire pour la nouvelle string
**
** snake_len calcule la taille exacte necessaire pour l'allocation
*/
#include <unistd.h>
#include <stdlib.h>

/*
** snake_len - calcule la longueur de la string snake_case resultante
** Pour chaque majuscule (sauf la 1ere): +1 pour le '_'
** Pour chaque char (majuscule ou non): +1 pour le char lui-meme
*/
int	snake_len(char *str)
{
	int	len;  /* Longueur totale de la string snake_case */
	int	i;    /* Index courant dans str original */

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && i != 0)
			len++;  /* +1 pour le '_' qu'on va ajouter (sauf position 0) */
		len++;      /* +1 pour le char lui-meme (converti en minuscule ou pas) */
		i++;
	}
	return (len);
}

char	*camel_to_snake(char *str)
{
	char	*snake;  /* La nouvelle string allouee avec malloc */
	int		len;     /* Taille necessaire = resultat de snake_len */
	int		i;       /* Index dans str source (l'original) */
	int		j;       /* Index dans snake destination (la nouvelle string) */

	len = snake_len(str);
	snake = (char *)malloc((len + 1) * sizeof(char));  /* +1 pour le '\0' final */
	i = 0;
	j = 0;
	while (j <= len)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (i != 0)                /* Si ce n'est PAS le premier char */
				snake[j++] = '_';      /* Ajouter un underscore avant */
			snake[j] = str[i] + 32;   /* Convertir majuscule -> minuscule (+32 ASCII) */
		}
		else
			snake[j] = str[i];  /* Char non majuscule: copier tel quel (y compris '\0') */
		j++;
		i++;
	}
	snake[len] = '\0';  /* S'assurer que la string est bien terminee */
	return (snake);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		write(1, camel_to_snake(argv[1]), snake_len(argv[1]));
	write(1, "\n", 1);
	return (0);
}
