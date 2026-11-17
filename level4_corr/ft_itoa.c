/*
** ft_itoa - convertit un int en string allouee avec malloc
** Gere tous les cas: positif, negatif, zero, et INT_MIN (-2147483648)
**
** Pourquoi utiliser 'long n' et pas 'int n'?
** INT_MIN = -2147483648. Si on fait n = -n avec int, on obtient un overflow
** car 2147483648 > INT_MAX (2147483647). Avec long, pas de probleme.
**
** Algorithme:
** 1. len_int calcule le nombre de chars necessaires (signe + chiffres)
** 2. malloc alloue len+1 octets (+1 pour '\0')
** 3. On remplit le tableau de DROITE a GAUCHE (--len donne la position)
** 4. On ajoute '-' en position 0 si negatif
*/
#include <stdlib.h>

/*
** len_int - calcule la longueur de la representation string de nbr
** Si nbr <= 0: au moins 1 char (le '0' ou le '-')
** On compte les chiffres en divisant par 10
*/
int	len_int(long nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
		len++;    /* Pour '0' si nbr==0, ou pour '-' si nbr<0 */
	while (nbr)
	{
		nbr /= 10;  /* Supprimer le dernier chiffre */
		len++;      /* Compter ce chiffre */
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long	n;       /* Copie en long pour eviter overflow avec INT_MIN */
	int		len;     /* Nombre de chars (sans le '\0') */
	int		neg;     /* Flag: 1 si negatif, 0 si positif ou zero */
	char	*result; /* La string allouee, remplie de droite a gauche */

	n = nbr;         /* Convertir en long AVANT toute operation */
	len = len_int(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';  /* Terminer la string */
	neg = 0;
	if (n < 0)
	{
		neg = 1;   /* Marquer comme negatif */
		n = -n;    /* Travailler avec la valeur absolue (safe car n est long) */
	}
	if (n == 0)
		result[0] = '0';  /* Cas special: 0 -> "0" */
	/* Remplir de droite a gauche: le dernier chiffre va a result[len-1] */
	while (n)
	{
		result[--len] = n % 10 + '0';  /* Chiffre des unites -> position courante */
		n /= 10;                        /* Passer au chiffre suivant */
	}
	if (neg)
		result[0] = '-';  /* Ajouter le signe moins en premiere position */
	return (result);
}
