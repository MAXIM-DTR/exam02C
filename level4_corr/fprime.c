/* fprime - affiche la décomposition en facteurs premiers
** Prototype : int main(int argc, char **argv)
** Usage : ./fprime <nombre>
**
** Exemples :
**   ./fprime 1    → 1
**   ./fprime 12   → 2*2*3
**   ./fprime 360  → 2*2*2*3*3*5
**   ./fprime      → (rien, juste une newline)
**
** Algorithme :
**   - On essaie tous les diviseurs à partir de 2
**   - Quand on trouve un diviseur, on divise et on remet div à 1
**   - On répète jusqu'à ce que nbr == div (dernier facteur trouvé)
*/

#include <stdlib.h>
#include <stdio.h>

void	fprime(int nbr)
{
	int	div;

	div = 1;
	if (nbr < 0)
		return ;
	if (nbr == 1)
		printf("1");
	/* On teste tous les entiers à partir de 2 */
	while (nbr > div++)
	{
		if (nbr % div == 0)
		{
			printf("%d", div);
			/* Si c'est le dernier facteur, on arrête */
			if (nbr == div)
				break ;
			printf("*");
			nbr /= div;
			/* On repart de 1 (div++ le mettra à 2) */
			div = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
