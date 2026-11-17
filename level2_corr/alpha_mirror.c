/*
** alpha_mirror - remplace chaque lettre par son "miroir" dans l'alphabet
** a <-> z, b <-> y, c <-> x ... m <-> n (casse inchangee)
** Ex: 'a' -> 'z', 'Z' -> 'A', 'd' -> 'w', 'M' -> 'N'
**
** Formule pour trouver le miroir:
** - Minuscule: miroir = 'z' - (c - 'a')
**   Explication: c - 'a' donne la position (0=a, 1=b... 25=z)
**   En soustrayant de 'z'(25), on obtient le miroir (25-0=25=z, 25-1=24=y...)
** - Majuscule: miroir = 'Z' - (c - 'A') (meme logique)
*/
#include <unistd.h>

void	alpha_mirror(char *str)
{
	char	mirror;  /* Le caractere miroir calcule */
	int		i;       /* Index courant dans str */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			mirror = 'z' - (str[i] - 'a');  /* Position depuis 'a', puis miroir depuis 'z' */
		else if (str[i] >= 'A' && str[i] <= 'Z')
			mirror = 'Z' - (str[i] - 'A');  /* Meme logique pour majuscules */
		else
			mirror = str[i];  /* Non-lettre: afficher tel quel */
		write(1, &mirror, 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
