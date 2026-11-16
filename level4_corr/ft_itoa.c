/* ft_itoa - convertit un int en string
** Gere les negatifs et INT_MIN (-2147483648)
** On utilise long pour ne pas avoir de probleme avec -INT_MIN */
#include <unistd.h>
#include <stdlib.h>

/* Compter le nombre de chiffres (+1 pour le signe si negatif) */
int	count_digits(long n)
{
	int	count;

	if (n <= 0)
		count = 1;  /* '0' ou le signe '-' */
	else
		count = 0;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int nbr)
{
	int		len;
	char	*str;
	int		is_neg;
	long	n;

	n = nbr;           /* Utiliser long pour gerer INT_MIN */
	is_neg = (n < 0);
	if (is_neg)
		n = -n;
	len = count_digits((long)nbr);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	/* Remplir la string de droite a gauche */
	while (len > 0 && n > 0)
	{
		len--;
		str[len] = n % 10 + '0';
		n /= 10;
	}
	if (is_neg)
		str[0] = '-';
	if (nbr == 0)
		str[0] = '0';
	return (str);
}
