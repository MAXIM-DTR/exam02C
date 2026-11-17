/*
** ft_strcmp - compare deux strings lexicographiquement (comme strcmp)
** Retourne: 0 si identiques, <0 si s1 < s2, >0 si s1 > s2
**
** Principe: avancer i tant que les chars sont egaux ET qu'on n'est pas
** a la fin des DEUX strings en meme temps
**
** La condition de sortie est subtile:
** - On continue si s1[i] == s2[i] (memes chars)
** - ET si au moins une des strings n'est pas terminee
**   (s1[i] != '\0' || s2[i] != '\0')
** On sort quand on trouve une difference OU quand on a parcouru les deux
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;  /* Index commun pour parcourir s1 et s2 en parallele */

	i = 0;
	/* Avancer tant que les chars sont identiques et qu'on n'est pas a la fin */
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	/* s1[i] - s2[i]:
	** = 0 si les deux sont '\0' (strings identiques)
	** < 0 si s1[i] < s2[i] (s1 vient avant s2 alphabetiquement)
	** > 0 si s1[i] > s2[i] (s1 vient apres s2 alphabetiquement) */
	return (s1[i] - s2[i]);
}
