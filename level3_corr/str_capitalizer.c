/*
** str_capitalizer - capitalise la PREMIERE lettre de chaque mot (reste en minuscule)
** ATTENTION: accepte PLUSIEURS arguments (loop sur argv)
** Chaque argument traite independamment, suivi d'un \n
** Si aucun argument: afficher seulement \n
**
** Logique: variable 'start'
** start = 1 au debut de la string ET apres chaque espace/tab
** start = 0 partout ailleurs (milieu d'un mot)
** Si start == 1 et lettre minuscule -> mettre en majuscule (c'est la 1ere lettre du mot)
** Si start == 0 et lettre majuscule -> mettre en minuscule (pas la 1ere lettre)
*/
#include <unistd.h>

void	capitalize(char *str)
{
	int		i;      /* Index courant */
	char	c;      /* Le char transforme */
	int		start;  /* Flag: 1 si on est au debut d'un mot, 0 si au milieu */

	i = 0;
	start = 1;  /* On commence au debut d'un mot (premiere lettre sera majuscule) */
	while (str[i])
	{
		c = str[i];
		if (start && c >= 'a' && c <= 'z')
			c = c - 32;    /* 1ere lettre du mot et minuscule -> majuscule */
		else if (!start && c >= 'A' && c <= 'Z')
			c = c + 32;    /* Pas 1ere lettre et majuscule -> minuscule */
		/* Mettre a jour start APRES avoir traite c */
		if (str[i] == ' ' || str[i] == '\t')
			start = 1;     /* Separateur = debut de prochain mot */
		else
			start = 0;     /* Char non separateur = milieu de mot */
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		capitalize(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)
		write(1, "\n", 1);
	return (0);
}
