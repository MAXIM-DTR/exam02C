/*
** ft_strcpy - copie la string src dans dst (incluant le '\0')
** Retourne dst
** Allowed: aucune
*/

char	*ft_strcpy(char *dst, char *src)
{
	int i;
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0'; // BUG: variable s'appelle 'dst' pas 'dest' → ne compile pas
	return (dst); // BUG: idem, changer dest → dst
}
