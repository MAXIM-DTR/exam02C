/*
** max - retourne le plus grand entier du tableau
** Retourne 0 si le tableau est vide
** Allowed: aucune
*/


int	max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				m;

	if (len == 0)
		return (0);
	m = tab[0];
	i = 1;
	while (i < len)
	{
		if (tab[i] > m)
			m = tab[i];
		i++;
	}
	return (m);
}
