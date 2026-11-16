/* ft_rrange - comme ft_range mais en ordre decroissant
** Retourne: [max-1, max-2, ..., min]
** Si min >= max, retourne NULL */
#include <unistd.h>
#include <stdlib.h>

int	*ft_rrange(int min, int max)
{
	int	*tab;
	int	i;
	int	val;

	if (min >= max)
		return (NULL);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (NULL);
	i = 0;
	val = max - 1;  /* Commencer par la valeur la plus grande */
	while (val >= min)
	{
		tab[i] = val;
		i++;
		val--;
	}
	return (tab);
}
