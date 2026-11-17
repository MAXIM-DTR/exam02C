/*
** lcm - retourne le Plus Petit Commun Multiple (PPCM) de a et b
** LCM = smallest positive integer divisible by BOTH a and b
**
** Methode simple (sans PGCD):
** Partir de multiple = a, puis a*2, a*3...
** Des que multiple est divisible par b -> c'est le PPCM
**
** Ex: lcm(4, 6)
** multiple=4: 4%6 != 0
** multiple=8: 8%6 != 0
** multiple=12: 12%6 == 0 -> PPCM = 12 ✓
**
** Si a ou b est 0: le LCM est 0 par convention (aucun multiple commun)
*/

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	multiple;  /* Le multiple courant de a qu'on teste */

	if (a == 0 || b == 0)
		return (0);  /* LCM(0, x) = 0 par definition */
	multiple = a;  /* Commencer avec a lui-meme (a * 1) */
	while (multiple % b != 0)  /* Tant que multiple n'est pas divisible par b */
		multiple += a;          /* Passer au multiple suivant de a */
	return (multiple);  /* Le premier multiple de a qui est aussi divisible par b */
}
