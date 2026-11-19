/*
** ft_strcmp - reproduit strcmp
** Compare s1 et s2 caractère par caractère
** Retourne 0 si égaux, <0 si s1<s2, >0 si s1>s2
** Allowed: aucune
*/


int	ft_strcmp(char *s1, char *s2)
{
	// avance tant que les deux chars sont identiques ET non-nuls
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	// diff des valeurs ASCII → 0 si égaux, <0 ou >0 sinon
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
