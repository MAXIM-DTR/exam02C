/*
** ft_strspn - reproduit strspn
** Retourne le nb de chars de s qui sont dans accept
** Allowed: aucune
*/

#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		// cherche s[i] dans accept
		while (accept[j] && accept[j] != s[i])
			j++;
		if (!accept[j])     // boucle finie sans trouver → char PAS dans accept
			return (i);
		i++;                // char trouvé dans accept → on continue
	}
	return (i);             // toute la chaîne est dans accept
}
