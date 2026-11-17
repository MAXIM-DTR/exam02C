/*
** search_and_replace - remplace chaque occurrence de search par replace dans str
** Usage: ./search_and_replace <string> <char_a_chercher> <char_de_remplacement>
**
** VERIFICATION CRITIQUE: argv[2] et argv[3] doivent etre EXACTEMENT 1 char
** Comment verifier qu'une string fait exactement 1 char?
** - argv[2][0] != '\0' : la string n'est pas vide (il y a au moins 1 char)
** - !argv[2][1]        : le 2eme char est '\0' (il n'y a pas plus de 1 char)
** Ces deux conditions ensemble = exactement 1 char
*/
#include <unistd.h>

void	search_and_replace(char *str, char search, char replace)
{
	int	i;  /* Index courant dans str */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == search)
			write(1, &replace, 1);  /* Trouver: afficher le char de remplacement */
		else
			write(1, &str[i], 1);   /* Pas trouve: afficher le char original */
		i++;
	}
}

int	main(int argc, char **argv)
{
	/* argc == 4: argv[0]=prog, argv[1]=string, argv[2]=search, argv[3]=replace
	** argv[2][0] && !argv[2][1] : argv[2] fait exactement 1 char
	** Meme verification pour argv[3] */
	if (argc == 4 && argv[2][0] && !argv[2][1] && argv[3][0] && !argv[3][1])
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);  /* Toujours \n a la fin */
	return (0);
}
