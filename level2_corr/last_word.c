/* last_word - affiche le dernier mot d'une string
** 1. Reculer pour sauter les espaces/tabs de fin
** 2. Marquer la fin du mot (end)
** 3. Reculer jusqu'au separateur (trouver le debut)
** 4. Afficher de start a end */
#include <unistd.h>

void	last_word(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (str[i])
		i++;
	i--;
	while (i >= 0 && (str[i] == ' ' || str[i] == '\t'))
		i--;
	end = i;
	while (i >= 0 && str[i] != ' ' && str[i] != '\t')
		i--;
	start = i + 1;
	while (start <= end)
		write(1, &str[start++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
