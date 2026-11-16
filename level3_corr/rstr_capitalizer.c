/* rstr_capitalizer - capitalise DERNIERE lettre de chaque mot
** IMPORTANT: accepte PLUSIEURS arguments (loop sur argv)
** Si argc == 1, afficher juste un newline
** is_sep: '\0', ' ', ou '\t'
** Logique: si lettre et prochain char est separateur -> majuscule */
#include <unistd.h>

int	is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int	is_sep(char c)
{
	return (c == '\0' || c == ' ' || c == '\t');
}

void	capitalize(char *str)
{
	int	i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if (c >= 'A' && c <= 'Z')
			c = c + 32;  /* D'abord mettre tout en minuscule */
		if (is_alpha(c) && is_sep(str[i + 1]))
			c = c - 32;  /* Si derniere lettre du mot -> majuscule */
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
