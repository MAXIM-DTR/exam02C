/*
** is_power_of_2 - détermine si n est une puissance de 2
** Retourne 1 si oui, 0 sinon
** Allowed: aucune
*/


int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);
	// astuce bits : puissance de 2 a exactement 1 bit à 1
	// ex: 8 = 1000, 7 = 0111 → 8 & 7 = 0000
	return ((n & (n - 1)) == 0);
}
