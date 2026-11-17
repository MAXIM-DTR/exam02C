/*
** ft_strcpy - copie la string s2 dans s1 (comme strcpy de la libc)
** Retourne s1 (le pointeur vers la destination)
**
** IMPORTANT: s1 doit etre assez grand pour contenir s2 + le '\0' final
** On copie char par char jusqu'au '\0' de s2 (non inclus dans la boucle)
** puis on ajoute le '\0' manuellement apres la boucle
*/

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;  /* Index pour parcourir les deux strings en meme temps */

	i = 0;
	/* Copier chaque char de s2 dans s1, s'arreter quand s2 se termine */
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];  /* s2[i] copie dans s1[i]: meme position, autre tableau */
		i++;
	}
	/* Apres la boucle, i pointe sur la position apres le dernier char copie */
	s1[i] = '\0';  /* Terminer la string copiee avec le caractere nul */
	return (s1);   /* Retourner le pointeur vers le debut de s1 */
}
