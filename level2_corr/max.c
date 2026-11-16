/* max - retourne la valeur maximum d'un tableau
** Commence avec tab[0] comme max, compare avec le reste */
#include <unistd.h>

int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int			max_val;

	max_val = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > max_val)
			max_val = tab[i];  /* Nouveau maximum trouve */
		i++;
	}
	return (max_val);
}
