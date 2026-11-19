/*
** ft_strcmp - reproduit strcmp
** Compare s1 et s2 caractère par caractère
** Retourne 0 si égaux, <0 si s1<s2, >0 si s1>s2
** Allowed: aucune
*/


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
