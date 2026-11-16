/* ft_range - tableau d'entiers de min a max (exclus)
** Alloue (max - min) entiers, remplit avec min, min+1, ..., max-1
** Si min >= max, retourne NULL */
#include <unistd.h>
#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
