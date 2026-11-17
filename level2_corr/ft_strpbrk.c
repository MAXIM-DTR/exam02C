/*
** ft_strpbrk - cherche dans s1 le 1er char qui apparait dans s2
** "Pointer break": retourne un pointeur vers ce char dans s1
** Retourne NULL si aucun char de s2 n'est trouve dans s1
**
** Algorithme: pour chaque char de s1, parcourir toute s2
** Des qu'on trouve une correspondance, retourner l'adresse dans s1
** L'adresse est un POINTEUR, pas un index -> return &s1[i]
*/

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;  /* Index dans s1: pour parcourir la string principale */
	int	j;  /* Index dans s2: pour chercher parmi les chars recherches */

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s1[i] == s2[j])         /* Trouvé! s1[i] est dans s2 */
				return ((char *)&s1[i]); /* Retourner l'ADRESSE du char dans s1 */
			j++;
		}
		i++;
	}
	return (0);  /* Aucun char de s2 trouve dans s1 */
}
