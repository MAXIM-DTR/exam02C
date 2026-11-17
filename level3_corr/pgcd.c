/*
** pgcd - Plus Grand Commun Diviseur de deux entiers strictement positifs
** PGCD = plus grand entier qui divise exactement les deux nombres
** Ex: pgcd(42, 10) = 2, pgcd(42, 12) = 6, pgcd(14, 77) = 7
**
** Methode simple: tester tous les diviseurs de 1 a min(a,b)
** Garder le plus grand qui divise EXACTEMENT les deux nombres
** On parcourt de 1 vers le haut (pas de haut en bas) pour garder facilement
** le maximum: on ecrase result chaque fois qu'on trouve un meilleur diviseur
**
** Utilise printf (autorise par le sujet, plus simple que write pour les entiers)
*/
#include <stdlib.h>
#include <stdio.h>

void	pgcd(int a, int b)
{
	int	result;  /* Le PGCD trouve jusqu'ici (mis a jour a chaque bon diviseur) */
	int	div;     /* Le diviseur candidat (teste de 1 a min(a,b)) */

	if (a < 0 || b < 0)
		return ;
	div = 1;    /* Commencer par 1 (divise toujours tout) */
	result = 0; /* Pas encore de PGCD trouve */
	while (div <= a && div <= b)  /* Tester jusqu'au plus petit des deux */
	{
		if (a % div == 0 && b % div == 0)
			result = div;  /* div divise les deux -> nouveau PGCD candidat (le plus grand jusqu'ici) */
		div++;
	}
	printf("%d", result);  /* Afficher le PGCD final */
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		pgcd(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
