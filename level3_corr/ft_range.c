/* ft_range - tableau de start a end (INCLUS des deux cotes)
** IMPORTANT: fonctionne dans les DEUX sens (start peut > end)
** Si start < end: croissant [start, start+1, ..., end]
** Si start > end: decroissant [start, start-1, ..., end]
** Taille = abs(end - start) + 1 */
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int	*result;
	int	i;
	int	len;

	if (start <= end)
		len = end - start + 1;
	else
		len = start - end + 1;
	result = (int *)malloc(sizeof(int) * len);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start <= end)
			result[i] = start + i;   /* Croissant */
		else
			result[i] = start - i;   /* Decroissant */
		i++;
	}
	return (result);
}
