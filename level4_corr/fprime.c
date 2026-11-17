/*
** fprime - decompose un entier en ses facteurs premiers
** Ex: 42 = 2*3*7, 225225 = 3*3*5*5*7*11*13, 1 = 1
** Affiche les facteurs en ordre croissant separes par '*'
**
** Algorithme:
** - div commence a 1, on fait div++ au debut de chaque iteration (via while(nbr > div++))
**   Donc div vaut 2 au 1er test effectif
** - Quand on trouve nbr % div == 0:
**   1. Afficher div
**   2. Si nbr == div: c'est le dernier facteur -> break
**   3. Sinon: afficher '*', diviser nbr par div, et RESET div a 1
**      (le reset assure qu'on reteste tous les diviseurs depuis 2 pour le nouveau nbr)
**
** Cas special: nbr = 1 -> afficher "1" directement (1 n'a pas de facteurs premiers)
*/
#include <stdlib.h>
#include <stdio.h>

void	fprime(int nbr)
{
	int	div;  /* Le diviseur candidat; commence a 1, div++ le passe a 2 au premier test */

	div = 1;
	if (nbr < 0)
		return ;       /* Nombre negatif: rien a afficher */
	if (nbr == 1)
		printf("1");   /* Cas special: 1 n'a pas de facteurs premiers */
	/* while (nbr > div++) : incrementer div AVANT la comparaison
	** => div vaut 2 au 1er tour, 3 au 2eme, etc. */
	while (nbr > div++)
	{
		if (nbr % div == 0)   /* div est un facteur de nbr */
		{
			printf("%d", div); /* Afficher le facteur */
			if (nbr == div)    /* nbr a ete reduit jusqu'a etre egal a div */
				break ;        /* C'est le dernier facteur: on a fini */
			printf("*");       /* Il reste d'autres facteurs: separer par '*' */
			nbr /= div;        /* Diviser nbr par ce facteur */
			div = 1;           /* Recommencer a chercher depuis 2 (div++ -> 2) */
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");  /* Toujours un newline a la fin (meme si aucun argument) */
	return (0);
}
