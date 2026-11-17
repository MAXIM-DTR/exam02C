/*
** ft_atoi - convertit une string en entier (reproduit atoi)
** Gere les whitespace en debut, le signe, et les chiffres
**
** WHITESPACE a sauter: exactement 6 types
** ' '(32), '\t'(9), '\n'(10), '\v'(11), '\f'(12), '\r'(13)
**
** SIGNE: '+' ou '-' (un seul, optionnel, apres les whitespace)
** Si '-': sign = -1 -> resultat sera negatif
**
** CHIFFRES: accumulation standard avec result = result * 10 + chiffre
** S'arrete des qu'un char n'est pas un chiffre ('0' a '9')
*/

int	ft_atoi(char *str)
{
	int	result;  /* Le nombre en cours de construction */
	int	sign;    /* 1 si positif, -1 si negatif */
	int	i;       /* Index courant dans str */

	i = 0;
	/* Sauter tous les whitespace (espace et les 5 types de whitespace 9-13) */
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	sign = 1;  /* Par defaut positif */
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;  /* Inverser le signe si '-' */
		i++;             /* Avancer apres le signe */
	}
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		/* str[i] - '0' convertit le char ASCII en chiffre (ex: '5' - '0' = 5) */
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);  /* Appliquer le signe au resultat final */
}
