/*
** rotone - decale chaque lettre de 1 position dans l'alphabet
** a -> b, b -> c ... y -> z, z -> a (wrap-around)
** Meme logique pour les majuscules: Z -> A
**
** Formule: ((c - base + 1) % 26) + base
** - c - base: position 0-25 dans l'alphabet
** - + 1: decaler d'une position
** - % 26: si on etait a 25 (z), on revient a 0 (a)
** - + base: revenir dans la plage ASCII correcte
*/
#include <unistd.h>

void	rotone(char *str)
{
	char	c;  /* Caractere transforme (on ne modifie pas str directement) */
	int		i;  /* Index courant */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			c = (str[i] - 'a' + 1) % 26 + 'a';  /* Minuscule */
		else if (str[i] >= 'A' && str[i] <= 'Z')
			c = (str[i] - 'A' + 1) % 26 + 'A';  /* Majuscule */
		else
			c = str[i];  /* Non-lettre: inchange */
		write(1, &c, 1);  /* Afficher le char transforme */
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
