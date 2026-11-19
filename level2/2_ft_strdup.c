/*
** ft_strdup - reproduit strdup
** Alloue et retourne une copie de src
** Allowed: malloc
*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		len;
	char	*copy;
	int		i;

	len = 0;
	while (src[len])
		len++;
	copy = malloc(len + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
