/*
** ft_strcspn - reproduit strcspn
** Retourne le nb de chars de s avant le 1er char de reject
** Allowed: aucune
*/

#include <stddef.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		// cherche s[i] dans reject
		while (reject[j] && reject[j] != s[i])
			j++;
		if (reject[j])      // boucle arrêtée sur un match → char trouvé dans reject
			return (i);
		i++;
	}
	return (i);             // aucun char de reject trouvé → retourne longueur totale
}
