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
		while (reject[j] && reject[j] != s[i])
			j++;
		if (reject[j])
			return (i);
		i++;
	}
	return (i);
}
