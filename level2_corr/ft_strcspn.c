/* ft_strcspn - longueur avant le premier char de reject
** Parcourt s, pour chaque char verifie s'il est dans reject
** Retourne la position du premier char trouve dans reject
** Ex: strcspn("hello world", " ") -> 5 */
#include <unistd.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);  /* Trouve un char rejecte -> stop */
			j++;
		}
		i++;
	}
	return (i);
}
