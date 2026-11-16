/* ft_atoi - convertit une string en entier
** 1. Sauter les espaces (et chars 9-13)
** 2. Lire le signe + ou -
** 3. Lire les chiffres un par un */
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	/* Sauter les whitespaces */
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	/* Lire le signe */
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	/* Lire les chiffres */
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
