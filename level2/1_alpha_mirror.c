/*
** alpha_mirror - remplace chaque lettre par son opposé alphabétique
** 'a'→'z', 'Z'→'A', 'd'→'w', 'M'→'N' (casse inchangée)
** Si argc != 2 : afficher seulement \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	c;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])
	{
		c = argv[1][i];
		if (c >= 'a' && c <= 'z')
			c = 'a' + 'z' - c;
		else if (c >= 'A' && c <= 'Z')
			c = 'A' + 'Z' - c;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
