/*
** ft_strpbrk - reproduit strpbrk
** Retourne un pointeur sur le 1er char de s1 présent dans s2
** NULL si aucun char de s2 trouvé dans s1
** Allowed: aucune
*/


char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		// cherche s1[i] dans s2
		while (s2[j] && s2[j] != s1[i])
			j++;
		if (s2[j])                      // match → retourne pointeur sur ce char dans s1
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);                      // aucun char de s2 trouvé dans s1
}
