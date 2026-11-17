/*
** ulstr - inverse la casse de chaque lettre (Upper<->Lower)
** Majuscule -> Minuscule, Minuscule -> Majuscule
** Non-lettres: inchanges
** ATTENTION: le fichier s'appelle ulstr.c (pas ultstr.c !)
**
** Pourquoi +32 et -32?
** En ASCII, la difference entre 'A'(65) et 'a'(97) est exactement 32
** Donc: Majuscule + 32 = Minuscule correspondante
**        Minuscule - 32 = Majuscule correspondante
** Ex: 'A'(65) + 32 = 'a'(97), 'z'(122) - 32 = 'Z'(90)
*/
#include <unistd.h>

void	ulstr(char *str)
{
	int	i;  /* Index courant dans str */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;        /* Majuscule -> minuscule (ajouter 32 en ASCII) */
			write(1, &str[i], 1);
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;        /* Minuscule -> majuscule (soustraire 32 en ASCII) */
			write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);  /* Non-lettre: afficher tel quel */
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ulstr(argv[1]);
	write(1, "\n", 1);
	return (0);
}
