/*
** ft_atoi_base - convertit une string depuis la base str_base vers base 10
** ATTENTION: le 2eme parametre est un INT (pas une string comme atoi_base usuel)
** Ex: ft_atoi_base("ff", 16) = 255
** Ex: ft_atoi_base("11", 2) = 3
** Ex: ft_atoi_base("-1A", 16) = -26
**
** Conversion char -> valeur:
** '0'-'9': valeur = char - '0'  (ex: '5' - '0' = 5)
** 'A'-'F': valeur = char - '7'  (car 'A'=65, '7'=55, 65-55=10 ✓)
** 'a'-'f': valeur = char - 'W'  (car 'a'=97, 'W'=87, 97-87=10 ✓)
** Majuscules et minuscules acceptees (meme valeur)
**
** Le '-' est interprete seulement s'il est le PREMIER char
*/

int	ft_atoi_base(const char *str, int base)
{
	char	*number;  /* Pointeur de parcours (cast depuis const char*) */
	int		result;   /* Le resultat accumule en base 10 */
	int		sign;     /* 1 si positif, -1 si negatif */
	int		i;        /* Index courant */

	i = 0;
	sign = 1;
	number = (char *)str;
	if (number[i] == '-')
	{
		sign *= -1;  /* Inverser le signe */
		i++;         /* Avancer apres le '-' */
	}
	result = 0;
	while (number[i] != '\0')
	{
		if (number[i] >= '0' && number[i] <= '9')
			result = result * base + number[i] - '0';    /* '0'-'9' : valeur 0-9 */
		else if (number[i] >= 'A' && number[i] <= 'F')
			result = result * base + number[i] - '7';    /* 'A'-'F' : valeur 10-15 */
		else if (number[i] >= 'a' && number[i] <= 'f')
			result = result * base + number[i] - 'W';    /* 'a'-'f' : valeur 10-15 */
		i++;
	}
	return (sign * result);
}
