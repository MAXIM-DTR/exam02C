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
		while (s2[j])
		{
			if (s1[i] == s2[j])
				return ((char *)(s1 + i));
			j++;
		}
		i++;
	}
	return (NULL);
}
