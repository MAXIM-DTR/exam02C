/* is_power_of_2 - verifie si n est une puissance de 2
** Astuce binaire: une puissance de 2 n'a qu'un seul bit a 1
** Exemple: 4 = 100, 3 = 011, 4 & 3 = 000 -> c'est une puissance!
** Exemple: 6 = 110, 5 = 101, 6 & 5 = 100 -> pas une puissance */
#include <unistd.h>

int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);               /* 0 n'est pas une puissance de 2 */
	return ((n & (n - 1)) == 0); /* 1 si une seule puissance, 0 sinon */
}
