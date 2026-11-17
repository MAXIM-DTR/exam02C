/*
** ft_rrange - comme ft_range mais le tableau va de end vers start (inverse)
** BIDIRECTIONNEL: fonctionne dans les deux sens
**
** Ex: ft_rrange(1, 3)  -> [3, 2, 1]       (commence par end=3, va vers start=1)
** Ex: ft_rrange(3, 1)  -> [1, 2, 3]       (commence par end=1, va vers start=3)
** Ex: ft_rrange(-1, 2) -> [2, 1, 0, -1]   (commence par 2, va vers -1)
**
** Comparaison ft_range vs ft_rrange:
** ft_range(1,3)  -> [1, 2, 3]  (de start vers end)
** ft_rrange(1,3) -> [3, 2, 1]  (de end vers start)
*/
#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	*result;  /* Le tableau alloue */
	int	i;        /* Index dans result */
	int	len;      /* Meme taille que ft_range */

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
			result[i] = end - i;  /* Commence par end, descend vers start */
		else
			result[i] = end + i;  /* Commence par end, monte vers start */
		i++;
	}
	return (result);
}
