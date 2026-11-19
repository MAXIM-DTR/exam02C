/*
** ft_strrev - inverse une chaîne en place
** Modifie str directement, retourne str
** Allowed: aucune
*/


char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (str[j])  // j → fin de chaîne
		j++;
	j--;            // j pointe sur le dernier char (avant '\0')
	while (i < j)   // swap jusqu'au milieu
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
