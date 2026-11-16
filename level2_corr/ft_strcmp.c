/* ft_strcmp - compare deux strings
** Avancer tant que les chars sont egaux ET qu'on n'est pas a la fin des DEUX
** Retourner la difference du premier char different */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
