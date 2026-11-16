/* ft_strspn - longueur du prefix contenant uniquement des chars de accept
** Pour chaque char de s, chercher dans accept
** Des qu'un char n'est pas dans accept, retourner la position */
#include <stddef.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i;
	size_t	j;
	int		found;

	i = 0;
	while (s[i])
	{
		j = 0;
		found = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
				found = 1;
			j++;
		}
		if (!found)
			return (i);
		i++;
	}
	return (i);
}
