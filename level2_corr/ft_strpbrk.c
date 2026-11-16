/* ft_strpbrk - 1ere occurrence dans s1 d'un char de s2
** Pour chaque char de s1, verifie s'il est dans s2
** Retourne le pointeur vers ce char, ou NULL */
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)&s1[i]);  /* Trouve! */
			j++;
		}
		i++;
	}
	return (NULL);
}
