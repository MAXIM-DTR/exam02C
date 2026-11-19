/*
** last_word - affiche le dernier mot de la chaîne + \n
** Un mot = délimité par espaces/tabs ou début/fin de chaîne
** Si argc != 2 ou pas de mot : afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	end;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (argv[1][i])          // i → fin de la chaîne
		i++;
	while (i > 0 && (argv[1][i - 1] == ' ' || argv[1][i - 1] == '\t'))
		i--;                    // recule en sautant les espaces de fin
	end = i;                    // sauvegarde la fin du dernier mot
	while (i > 0 && argv[1][i - 1] != ' ' && argv[1][i - 1] != '\t')
		i--;                    // recule jusqu'au début du dernier mot
	write(1, argv[1] + i, end - i);  // écrit exactement end-i chars
	write(1, "\n", 1);
	return (0);
}
