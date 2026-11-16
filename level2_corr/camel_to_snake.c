/* camel_to_snake - camelCase -> snake_case
** Chaque majuscule devient '_' + minuscule
** Ex: helloWorld -> hello_world */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	char	under;
	char	lower;

	if (argc == 2)
	{
		i = 0;
		while (argv[1][i])
		{
			if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				under = '_';
				lower = argv[1][i] + 32;  /* +32 = minuscule en ASCII */
				write(1, &under, 1);
				write(1, &lower, 1);
			}
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
