/*
** ft_strlen - retourne la longueur d'une string (sans le '\0')
** Allowed: aucune
*/

int	ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
