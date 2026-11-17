/*
** ft_strrev - inverse une string sur place (modifie la string originale)
** Retourne str (le meme pointeur passe en parametre)
**
** Technique des deux pointeurs:
** - i part du debut (position 0)
** - j part de la fin (position len-1)
** - On echange str[i] et str[j] puis on rapproche les deux indexes
** - On s'arrete quand i >= j (indexes se croisent = milieu atteint)
**
** Ex: "hello"
** i=0 j=4: echange 'h' et 'o' -> "oellh"
** i=1 j=3: echange 'e' et 'l' -> "olleh"
** i=2 j=2: i >= j, on s'arrete -> "olleh" = "olleh" ✓
*/

char	*ft_strrev(char *str)
{
	int		i;    /* Index qui part du debut */
	int		j;    /* Index qui part de la fin */
	char	tmp;  /* Variable temporaire pour l'echange (comme ft_swap) */

	i = 0;
	j = 0;
	while (str[j])  /* Trouver la fin de la string */
		j++;
	j--;  /* j pointe maintenant sur le dernier char (avant '\0') */
	while (i < j)  /* Continuer tant que les deux indexes ne se sont pas croises */
	{
		tmp = str[i];   /* Sauvegarder str[i] */
		str[i] = str[j]; /* str[i] prend la valeur de str[j] */
		str[j] = tmp;   /* str[j] prend l'ancienne valeur de str[i] */
		i++;  /* Avancer depuis le debut */
		j--;  /* Reculer depuis la fin */
	}
	return (str);  /* Retourner le meme pointeur (string modifiee en place) */
}
