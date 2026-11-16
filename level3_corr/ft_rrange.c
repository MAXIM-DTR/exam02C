/* ft_rrange - comme ft_range mais en ordre inverse
** Si start < end: [end, end-1, ..., start]
** Si start > end: [end, end+1, ..., start]
** Meme taille que ft_range, ordre inverse */
#include <stdlib.h>

int	*ft_rrange(int start, int end)
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
			result[i] = end - i;   /* Commence par end, va vers start */
		else
			result[i] = end + i;   /* Commence par end, va vers start */
		i++;
	}
	return (result);
}
