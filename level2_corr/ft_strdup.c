/*
** ft_strdup - alloue et retourne une copie d'une string (reproduit strdup)
** Parametre src: la string originale a dupliquer
** Retourne: pointeur vers la nouvelle copie (a liberer avec free)
**
** Etapes:
** 1. Calculer la longueur de src (pour savoir combien allouer)
** 2. malloc(len + 1): +1 pour le '\0' de fin
** 3. Copier chaque char de src dans dup
** 4. Terminer avec '\0'
*/
#include <stdlib.h>

/*
** ft_strlen - helper pour calculer la longueur de src
** (on ne peut pas utiliser la vraie strlen car ce serait tricher)
*/
int	ft_strlen(char *src)
{
	int	len;  /* Compteur de chars */

	len = 0;
	while (src[len] != '\0')
		len++;
	return (len);  /* Nombre de chars SANS le '\0' */
}

char	*ft_strdup(char *src)
{
	char	*dup;  /* Pointeur vers la nouvelle string allouee */
	int		len;   /* Longueur de src (sans le '\0') */
	int		i;     /* Index pour la copie */

	len = ft_strlen(src);
	/* len + 1 octets: len chars + 1 pour le '\0' de terminaison */
	dup = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];  /* Copier char par char */
		i++;
	}
	dup[i] = '\0';  /* Ajouter le terminateur (dup[len] = '\0') */
	return (dup);   /* Retourner le pointeur vers la copie */
}
