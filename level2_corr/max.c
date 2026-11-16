/* max - retourne la valeur maximum d'un tableau
** Si len == 0 retourne 0
** Commence avec tab[0], compare le reste */

int	max(int *tab, unsigned int len)
{
	int				result;
	unsigned int	i;

	if (len == 0)
		return (0);
	result = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return (result);
}
