/* ft_atoi_base - convertit une string depuis une base donnee
** Ex: ft_atoi_base("11", "01") = 3 (binaire)
** Ex: ft_atoi_base("ff", "0123456789abcdef") = 255
** Pour chaque char: trouver son index dans la base,
** puis: resultat = resultat * taille_base + index */
#include <unistd.h>

int	char_index(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	len;
	int	idx;
	int	i;

	/* Calculer la taille de la base */
	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	result = 0;
	i = 0;
	while (str[i])
	{
		idx = char_index(base, str[i]);
		if (idx == -1)
			break;  /* Char inconnu dans la base -> stop */
		result = result * len + idx;
		i++;
	}
	return (result);
}
