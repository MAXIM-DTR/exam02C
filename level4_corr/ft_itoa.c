/* ft_itoa - convertit un int en chaîne de caractères
** Prototype : char *ft_itoa(int nbr);
** - nbr : le nombre à convertir
** Retourne une chaîne allouée avec malloc (à libérer avec free)
**
** Exemples :
**   ft_itoa(0)           → "0"
**   ft_itoa(42)          → "42"
**   ft_itoa(-98765)      → "-98765"
**   ft_itoa(-2147483648) → "-2147483648"
**
** Astuce : on utilise un long pour éviter le dépassement avec INT_MIN
*/

#include <stdlib.h>

/* Calcule le nombre de caractères nécessaires (signe inclus) */
int	len_int(long nbr)
{
	int	len;

	len = 0;
	/* Pour 0 ou les négatifs, on a au moins 1 chiffre */
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nbr)
{
	long	n;
	int		len;
	int		neg;
	char	*result;

	n = nbr; /* Convertir en long pour gérer INT_MIN */
	len = len_int(n);
	result = malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	neg = 0;
	if (n < 0)
	{
		neg = 1;
		n = -n; /* Rendre positif */
	}
	if (n == 0)
		result[0] = '0';
	/* Remplir de droite à gauche */
	while (n)
	{
		result[--len] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		result[0] = '-';
	return (result);
}
