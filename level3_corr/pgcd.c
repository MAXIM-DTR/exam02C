/* pgcd - Plus Grand Commun Diviseur
** Methode: tester tous les diviseurs de 1 a min(a,b)
** Garder le plus grand qui divise les deux
** Utilise printf */
#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int	result;
	int	div;

	if (a < 0 || b < 0)
		return ;
	div = 1;
	result = 0;
	while (div <= a && div <= b)
	{
		if (a % div == 0 && b % div == 0)
			result = div;  /* Mettre a jour le plus grand diviseur commun */
		div++;
	}
	printf("%d", result);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
