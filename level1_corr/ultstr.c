/* ultstr - inverse la casse de chaque lettre
** Majuscule -> minuscule, minuscule -> majuscule
** Autres chars inchanges */
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
			if (c >= 'A' && c <= 'Z')
				c = c + 32;   /* Majuscule -> minuscule (+32 en ASCII) */
			else if (c >= 'a' && c <= 'z')
				c = c - 32;   /* Minuscule -> majuscule (-32 en ASCII) */
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
