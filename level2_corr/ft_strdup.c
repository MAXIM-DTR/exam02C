/* ft_strdup - duplique une string avec malloc
** 1. Calculer la longueur
** 2. Allouer longueur + 1 octets (pour le '\0')
** 3. Copier char par char */
#include <unistd.h>
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*copy;
	int	len;
	int	i;

	len = 0;
	while (s[len])
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
