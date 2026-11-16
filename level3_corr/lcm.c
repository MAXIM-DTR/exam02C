/* lcm - Plus Petit Commun Multiple
** Methode simple: multiplier par a jusqu'a trouver un multiple de b
** multiple = a, puis a*2, a*3... jusqu'a multiple % b == 0
** ATTENTION: retourne unsigned int, pas de printf! */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	multiple;

	if (a == 0 || b == 0)
		return (0);
	multiple = a;
	while (multiple % b != 0)
		multiple += a;
	return (multiple);
}
