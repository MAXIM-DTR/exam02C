/* ft_strlen - retourne la longueur d'une string
** Compte les chars jusqu'au '\0' (non inclus) */
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
