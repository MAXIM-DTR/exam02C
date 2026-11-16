/* ft_atoi_base - convertit string depuis base numerique int
** ATTENTION: le 2eme arg est un INT (pas une string!)
** Ex: ft_atoi_base("ff", 16) = 255
** Ex: ft_atoi_base("11", 2) = 3
** Pour hexa: A-F = 10-15 avec char - '7' (car 'A' - '7' = 10)
**            a-f = 10-15 avec char - 'W' (car 'a' - 'W' = 10) */

int	ft_atoi_base(const char *str, int base)
{
	char	*number;
	int		result;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	number = (char *)str;
	if (number[i] == '-')
	{
		sign *= -1;
		i++;
	}
	result = 0;
	while (number[i] != '\0')
	{
		if (number[i] >= '0' && number[i] <= '9')
			result = result * base + number[i] - '0';
		else if (number[i] >= 'A' && number[i] <= 'F')
			result = result * base + number[i] - '7';  /* 'A'-'7' = 10 */
		else if (number[i] >= 'a' && number[i] <= 'f')
			result = result * base + number[i] - 'W';  /* 'a'-'W' = 10 */
		i++;
	}
	return (sign * result);
}
