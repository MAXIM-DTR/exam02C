/*
** paramsum - affiche le NOMBRE de parametres passes au programme
** PIEGE FREQUENT: le sujet dit "nombre de parametres", pas "somme de leurs valeurs"
** ./paramsum 1 2 3 5 7 24 -> affiche 6 (pas 1+2+3+5+7+24=42)
**
** argc = "argument count" = nombre d'arguments Y COMPRIS argv[0] (le nom du prog)
** Donc argc - 1 = nombre de vrais arguments passes par l'utilisateur
** Ex: ./paramsum a b c -> argc=4, argc-1=3
** Ex: ./paramsum        -> argc=1, argc-1=0
*/
#include <unistd.h>

/*
** ft_putnbr - affiche un entier avec write() (recursif)
** Affiche chaque chiffre du nombre, de gauche a droite
*/
void	ft_putnbr(int n)
{
	char	c;  /* Le char du chiffre a afficher */

	if (n >= 10)
		ft_putnbr(n / 10);  /* Afficher d'abord les chiffres de gauche */
	c = n % 10 + '0';       /* Convertir chiffre -> char ASCII */
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	(void)argv;        /* argv n'est pas utilise: on evite le warning compilateur */
	ft_putnbr(argc - 1);  /* argc - 1 = nb d'arguments passes par l'utilisateur */
	write(1, "\n", 1);
	return (0);
}
