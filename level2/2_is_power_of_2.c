/*
** is_power_of_2 - détermine si n est une puissance de 2
** Retourne 1 si oui, 0 sinon
** Allowed: aucune
*/


int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	return ((n & (n - 1)) == 0);
}
