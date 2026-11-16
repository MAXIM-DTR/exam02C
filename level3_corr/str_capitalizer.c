/* str_capitalizer - capitalise la PREMIERE lettre de chaque mot
** Toutes les autres lettres en minuscule
** Methode: suivre si on est au debut d'un mot (apres un espace) */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;
	int	new_word;

	if (argc == 2)
	{
		i = 0;
		new_word = 1;  /* Debut de string = debut de mot */
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c == ' ')
			{
				new_word = 1;  /* Apres espace = nouveau mot */
				write(1, &c, 1);
			}
			else if (c >= 'a' && c <= 'z')
			{
				if (new_word)
					c = c - 32;  /* Premiere lettre -> majuscule */
				new_word = 0;
				write(1, &c, 1);
			}
			else if (c >= 'A' && c <= 'Z')
			{
				if (!new_word)
					c = c + 32;  /* Pas premiere lettre -> minuscule */
				new_word = 0;
				write(1, &c, 1);
			}
			else
			{
				new_word = 0;
				write(1, &c, 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
