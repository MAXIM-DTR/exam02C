/*
** is_power_of_2 - verifie si n est une puissance de 2 (1, 2, 4, 8, 16, 32...)
** Retourne 1 si oui, 0 sinon
**
** Methode: diviser par 2 repetitivement
** Une puissance de 2 est un nombre dont la decomposition factorielle ne contient que 2
** Donc si on divise par 2 jusqu'a obtenir un impair, ce doit etre 1
**
** Ex: n=8: 8/2=4, 4/2=2, 2/2=1 -> impair est 1 -> puissance de 2 ✓
** Ex: n=6: 6/2=3 -> impair est 3 -> pas une puissance de 2 ✗
** Ex: n=0: cas special -> pas une puissance de 2 (retourner 0)
*/

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);  /* 0 n'est pas une puissance de 2 */
	/* Diviser par 2 tant que n est pair (n % 2 == 0) */
	while (n % 2 == 0)
		n /= 2;
	/* Apres toutes les divisions, n vaut soit 1 (puissance de 2) soit autre chose */
	return (n == 1);  /* Retourne 1 si n==1, 0 sinon */
}
