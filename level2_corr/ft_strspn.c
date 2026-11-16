/* ft_strspn - longueur du prefix contenant uniquement des chars de accept
** Pour chaque char de s, verifie s'il est dans accept
** Des qu'un char n'est pas dans accept, on retourne la position */
#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	int	i;
	int	j;
	int	found;

	i = 0;
	while (s[i])
	{
		found = 0;
		j = 0;
		while (accept[j])
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
			return (i);  /* Ce char n'est pas dans accept -> stop */
		i++;
	}
	return (i);
}
