/* search_and_replace - remplace search par replace dans str
** IMPORTANT: argv[2] et argv[3] doivent etre exactement 1 char
** Verifier: argv[2][0] existe ET argv[2][1] n'existe pas */
#include <unistd.h>

void	search_and_replace(char *str, char search, char replace)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			write(1, &replace, 1);
		else
			write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4 && argv[2][0] && !argv[2][1] && argv[3][0] && !argv[3][1])
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
