/* search_and_replace - remplace un char par un autre
** Args: string char_a_remplacer char_de_remplacement
** Si argc != 4, ne rien afficher */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	c;

	if (argc == 4)
	{
		i = 0;
		while (argv[1][i])
		{
			c = argv[1][i];
			if (c == argv[2][0])   /* Si c'est le char a remplacer */
				c = argv[3][0];     /* Remplacer par le nouveau char */
			write(1, &c, 1);
			i++;
		}
		write(1, "\n", 1);
	}
	return (0);
}
