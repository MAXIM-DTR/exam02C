/* ft_strrev - inverse une string sur place
** Echanger le 1er avec le dernier, le 2eme avec l'avant-dernier...
** On utilise deux indices: i depuis le debut, j depuis la fin */
#include <unistd.h>

char	*ft_strrev(char *str)
{
	int	i;
	int	j;
	char	temp;

	i = 0;
	while (str[i])
		i++;
	j = i - 1;
	i = 0;
	while (i < j)
	{
		/* Echanger str[i] et str[j] */
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}
