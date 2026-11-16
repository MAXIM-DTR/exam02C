/* ft_strlen - retourne la longueur d'une string
** Compte les chars jusqu'au '\0' */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
