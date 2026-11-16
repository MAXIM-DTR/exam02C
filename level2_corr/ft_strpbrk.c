/* ft_strpbrk - cherche 1er char de s2 dans s1
** Pour chaque char de s1, parcourir s2
** Retourner pointeur vers le char trouve, 0 si rien */

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
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
