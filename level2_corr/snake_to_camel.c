/* snake_to_camel - snake_case -> camelCase
** Pour chaque '_': sauter le _ et mettre la lettre suivante en majuscule
** Ex: hello_world -> helloWorld */
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
			if (argv[1][i] == '_' && argv[1][i + 1])
			{
				i++;
				c = argv[1][i] - 32;  /* Mettre en majuscule (-32 en ASCII) */
				write(1, &c, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
