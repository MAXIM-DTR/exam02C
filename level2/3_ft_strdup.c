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
	while (src[len])        // calcule la longueur de src
		len++;
	copy = malloc(len + 1); // +1 pour le '\0' final
	if (!copy)
		return (NULL);
	i = 0;
	while (i <= len)        // copie len chars + le '\0' (car i <= len)
	{
		copy[i] = src[i];
		i++;
	}
	return (copy);
}
