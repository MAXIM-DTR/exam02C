/* str_capitalizer - capitalise PREMIERE lettre de chaque mot
** IMPORTANT: accepte PLUSIEURS arguments (loop sur argv)
** Si argc == 1, afficher juste un newline
** start=1 au debut et apres chaque espace/tab */
#include <unistd.h>

void	capitalize(char *str)
{
	int	i;
	char	c;
	int	start;

	i = 0;
	start = 1;  /* On commence au debut d'un mot */
	while (str[i])
	{
		c = str[i];
		if (start && c >= 'a' && c <= 'z')
			c = c - 32;   /* Premiere lettre du mot -> majuscule */
		else if (!start && c >= 'A' && c <= 'Z')
			c = c + 32;   /* Pas premiere lettre -> minuscule */
		if (str[i] == ' ' || str[i] == '\t')
			start = 1;    /* Apres espace = nouveau mot */
		else
			start = 0;
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
