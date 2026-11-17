/*
** ft_strcspn - longueur du prefix de s avant le 1er char de reject
** "Complementary span": taille du segment initial qui ne contient AUCUN char de reject
** Retourne size_t (entier non-signe comme la libc)
**
** Algorithme: double boucle
** - Boucle externe: parcourir s char par char
** - Boucle interne: pour chaque char de s, chercher dans tout reject
** - Des qu'on trouve un match: retourner i (nb de chars avant ce match)
** - Si on parcourt tout s sans match: retourner i (longueur totale de s)
*/
#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;  /* Index dans s: compte les chars avant le 1er char de reject */
	size_t	j;  /* Index dans reject: pour chercher le char courant de s */

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])  /* s[i] est dans reject: on s'arrete ici */
				return (i);          /* i = nombre de chars avant ce point */
			j++;
		}
		i++;  /* s[i] n'est pas dans reject: continuer */
	}
	return (i);  /* Fin de s atteinte sans trouver de char de reject */
}
