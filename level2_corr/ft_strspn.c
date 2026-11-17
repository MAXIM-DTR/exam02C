/*
** ft_strspn - longueur du prefix de s compose uniquement de chars de accept
** "Span": taille du segment initial qui contient SEULEMENT des chars de accept
** Opposé de ft_strcspn
**
** Algorithme:
** - Pour chaque char de s, verifier s'il est dans accept
** - Si OUI: continuer, incrementer i
** - Si NON: retourner i immediatement
** On utilise found pour signaler si le char courant est dans accept
*/
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;      /* Index dans s: compte les chars qui sont dans accept */
	size_t	j;      /* Index dans accept: pour chercher le char courant de s */
	int		found;  /* Flag: 1 si s[i] est dans accept, 0 sinon */

	i = 0;
	while (s[i])
	{
		j = 0;
		found = 0;  /* Reinitialiser pour chaque nouveau char de s */
		while (accept[j])
		{
			if (s[i] == accept[j])
				found = 1;  /* s[i] est dans accept */
			j++;
		}
		if (!found)
			return (i);  /* s[i] n'est PAS dans accept -> fin du span */
		i++;
	}
	return (i);  /* Toute s est composee de chars de accept */
}
