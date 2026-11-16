/* is_power_of_2 - verifie si n est une puissance de 2
** Methode: diviser par 2 jusqu'a obtenir un nombre impair
** Si ce nombre est 1 -> c'etait une puissance de 2 */

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return (n == 1);
}
