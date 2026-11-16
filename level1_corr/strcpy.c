/* ft_strcpy - copie src dans dst
** Copie char par char jusqu'au '\0' inclus
** Retourne dst */
#include <unistd.h>

char	*ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])  /* Copier tant que pas fin de src */
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';  /* Terminer la string copiee */
	return (dst);
}
