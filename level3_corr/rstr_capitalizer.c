/* rstr_capitalizer - capitalise la DERNIERE lettre de chaque mot
** Toutes les autres lettres en minuscule
** Methode: si le prochain char est un espace ou fin de string
** -> c'est la derniere lettre -> mettre en majuscule */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c >= 'a' && c <= 'z')
			{
				/* Derniere lettre du mot? */
				if (argv[1][i + 1] == ' ' || argv[1][i + 1] == '\0')
					c = c - 32;  /* En majuscule */
			}
			else if (c >= 'A' && c <= 'Z')
			{
				/* Pas la derniere lettre? -> minuscule */
				if (argv[1][i + 1] != ' ' && argv[1][i + 1] != '\0')
					c = c + 32;
			}
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
