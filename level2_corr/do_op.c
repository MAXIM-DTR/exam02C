/*
** do_op - effectue une operation arithmetique entre deux entiers
** Usage: ./do_op <nb1> <operateur> <nb2>
** Operateurs acceptes: + - * / %
**
** IMPORTANT: utilise printf (pas write) car printf gere directement
** la conversion int -> string pour nous
** Le sujet autorise printf, donc on l'utilise
**
** atoi(str) convertit la string argv en int pour le calcul
** argv[2][0] prend le premier char de la string operateur ('+', '-', etc.)
*/
#include <stdio.h>
#include <stdlib.h>

/*
** do_op - calcule et retourne le resultat de l'operation a op b
** Parametres: a = premier entier, op = l'operateur, b = deuxieme entier
** Retourne: le resultat de l'operation (0 si operateur invalide)
*/
int	do_op(int a, char op, int b)
{
	int	result;  /* Le resultat de l'operation */

	result = 0;
	if (op == '*')
		result = a * b;
	else if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '/')
		result = a / b;  /* Division entiere: 7/2 = 3 (pas 3.5) */
	else if (op == '%')
		result = a % b;  /* Modulo: reste de la division, ex: 7%3 = 1 */
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		/* atoi convertit argv[1] et argv[3] (strings) en int
		** argv[2][0] prend le 1er char de argv[2] pour obtenir l'operateur */
		printf("%i", do_op(atoi(argv[1]), argv[2][0], atoi(argv[3])));
	printf("\n");
	return (0);
}
