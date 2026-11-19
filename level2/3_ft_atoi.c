/*
** ft_atoi - convertit une chaîne en int (comme atoi)
** Gère les espaces/tabs en début, signe + ou -
** S'arrête au premier char non numérique
** Allowed: aucune
*/


int	ft_atoi(const char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	// 1) sauter les espaces et whitespace du début
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	// 2) lire le signe (si présent)
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	// 3) lire les chiffres et construire le nombre
	while (*str >= '0' && *str <= '9')
		result = result * 10 + *str++ - '0';  // *str++ lit ET avance
	return (result * sign);
}
