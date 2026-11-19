/*
** union - affiche les chars des deux chaînes sans doublons
** Dans l'ordre d'apparition dans la ligne de commande + \n
** Si argc != 3 : afficher \n
** Allowed: write
*/

#include <unistd.h>

int	main(int argc, char **argv)
{
	char	seen[256];  // tableau de 256 cases (1 par valeur ASCII possible)
	int		i;
	int		j;

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	i = 0;
	while (i < 256)
		seen[i++] = 0;  // initialise tout à 0 (pas encore vu)
	i = 0;
	while (argv[1][i])
	{
		if (!seen[(unsigned char)argv[1][i]])   // pas encore vu ce char
		{
			seen[(unsigned char)argv[1][i]] = 1; // marque comme vu
			write(1, &argv[1][i], 1);
		}
		i++;
	}
	j = 0;
	while (argv[2][j])  // même chose pour argv[2]
	{
		if (!seen[(unsigned char)argv[2][j]])
		{
			seen[(unsigned char)argv[2][j]] = 1;
			write(1, &argv[2][j], 1);
		}
		j++;
	}
	write(1, "\n", 1);
	return (0);
}
