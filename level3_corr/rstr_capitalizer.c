/*
** rstr_capitalizer - capitalise la DERNIERE lettre de chaque mot (reste en minuscule)
** ATTENTION: accepte PLUSIEURS arguments (loop sur argv de 1 a argc-1)
** Chaque argument est traite independamment et suivi d'un \n
** Si aucun argument (argc == 1): afficher seulement \n
**
** Logique de capitalisation:
** - D'abord: mettre la lettre courante en MINUSCULE (c + 32 si majuscule)
** - Ensuite: si c'est une lettre ET le char SUIVANT est un separateur
**   (espace, tab, ou '\0') -> c'est la DERNIERE lettre du mot -> mettre en MAJUSCULE
**
** is_sep inclut '\0' car la derniere lettre de la string est aussi la derniere du mot
*/
#include <unistd.h>

/* Retourne 1 si c est une lettre (minuscule ou majuscule) */
int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/* Retourne 1 si c est un separateur de mot ou fin de string */
int	is_sep(char c)
{
	return (c == '\0' || c == ' ' || c == '\t');
}

void	capitalize(char *str)
{
	int		i;  /* Index courant dans str */
	char	c;  /* Le char transforme (d'abord minuscule, puis majuscule si derniere lettre) */

	i = 0;
	while (str[i])
	{
		c = str[i];
		/* Etape 1: mettre en minuscule (meme si c'etait deja une minuscule) */
		if (c >= 'A' && c <= 'Z')
			c = c + 32;  /* Majuscule -> minuscule */
		/* Etape 2: si c'est une lettre ET le char suivant est un separateur
		** -> c'est la derniere lettre du mot -> passer en majuscule */
		if (is_alpha(c) && is_sep(str[i + 1]))
			c = c - 32;  /* Minuscule -> majuscule (-32 en ASCII) */
		write(1, &c, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;  /* Index dans argv (commence a 1 car argv[0] = nom du prog) */

	i = 1;
	while (i < argc)  /* Traiter chaque argument */
	{
		capitalize(argv[i]);
		write(1, "\n", 1);
		i++;
	}
	if (argc == 1)       /* Aucun argument: afficher seulement \n */
		write(1, "\n", 1);
	return (0);
}
