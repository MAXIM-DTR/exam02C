/* rot_13 - chiffrement ROT13
** Chaque lettre est decalee de 13 dans l'alphabet
** (a-m -> n-z, n-z -> a-m), majuscules pareil
** Formule: (c - 'a' + 13) % 26 + 'a' */
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
				c = (c - 'a' + 13) % 26 + 'a';
			else if (c >= 'A' && c <= 'Z')
				c = (c - 'A' + 13) % 26 + 'A';
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
