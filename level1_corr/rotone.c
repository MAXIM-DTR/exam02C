/* rotone - decale chaque lettre d'un cran
** z -> a, Z -> A, les autres lettres +1 */
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
			if (c == 'z')
				c = 'a';        /* z tourne vers a */
			else if (c == 'Z')
				c = 'A';        /* Z tourne vers A */
			else if ((c >= 'a' && c <= 'y') || (c >= 'A' && c <= 'Y'))
				c = c + 1;      /* Toutes les autres lettres +1 */
			write(1, &c, 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
