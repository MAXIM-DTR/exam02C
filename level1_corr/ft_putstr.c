/*
** ft_putstr - affiche une string sur la sortie standard (stdout)
** Parametre str: la string a afficher (tableau de chars termine par '\0')
**
** write(1, ptr, n) : fd=1 (stdout), ptr=adresse, n=nb octets a ecrire
** On ne peut pas ecrire toute la string d'un coup car on ne connait pas
** sa longueur d'avance -> on ecrit 1 char a la fois jusqu'au '\0'
*/
#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;  /* Index du char courant dans str */

	i = 0;
	/* str[i] != '\0' : continuer tant qu'on n'est pas a la fin de la string */
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);  /* &str[i] = adresse du char a la position i */
		i++;
	}
	/* Pas de newline ici: ft_putstr affiche exactement ce qu'on lui donne */
}
