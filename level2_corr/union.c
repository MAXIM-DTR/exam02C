/* union - affiche l'union de deux strings
** Chaque char de s1 puis s2, sans doublons, dans l'ordre de 1ere apparition
** On utilise un tableau de 256 cases pour tracker les chars deja affiches */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	printed[256];

	if (argc == 3)
	{
		/* Initialiser tous les flags a 0 */
		i = 0;
		while (i < 256)
		{
			printed[i] = 0;
			i++;
		}
		/* Parcourir s1 */
		i = 0;
		while (argv[1][i])
		{
			if (!printed[(unsigned char)argv[1][i]])
			{
				write(1, &argv[1][i], 1);
				printed[(unsigned char)argv[1][i]] = 1;
			}
			i++;
		}
		/* Parcourir s2 */
		i = 0;
		while (argv[2][i])
		{
			if (!printed[(unsigned char)argv[2][i]])
			{
				write(1, &argv[2][i], 1);
				printed[(unsigned char)argv[2][i]] = 1;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
