/*
** ft_range - alloue et retourne un tableau [start..end] inclus (les deux bornes)
** BIDIRECTIONNEL: fonctionne si start < end OU si start > end
**
** Ex: ft_range(1, 3)  -> [1, 2, 3]       (croissant)
** Ex: ft_range(3, 1)  -> [3, 2, 1]       (decroissant)
** Ex: ft_range(-1, 2) -> [-1, 0, 1, 2]
** Ex: ft_range(0, 0)  -> [0]             (un seul element)
**
** TAILLE du tableau: abs(end - start) + 1
** Le +1 est pour inclure les deux bornes
** Ex: ft_range(1,3): 3-1+1 = 3 elements ✓
*/
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*result;  /* Le tableau alloue avec malloc */
	int	i;        /* Index courant dans result (0, 1, 2...) */
	int	len;      /* Nombre d'elements = abs(end-start) + 1 */

	/* Calculer la taille: abs(end-start) + 1 (inclure les deux bornes) */
	if (start <= end)
		len = end - start + 1;  /* Croissant ou egal */
	else
		len = start - end + 1;  /* Decroissant */
	result = (int *)malloc(sizeof(int) * len);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start <= end)
			result[i] = start + i;  /* Croissant: start, start+1, start+2... */
		else
			result[i] = start - i;  /* Decroissant: start, start-1, start-2... */
		i++;
	}
	return (result);
}
