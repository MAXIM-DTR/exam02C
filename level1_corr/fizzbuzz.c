/*
** fizzbuzz - affiche les nombres de 1 a 100 avec regles fizzbuzz
**
** REGLE CLE: tester 15 (multiple de 3 ET 5) EN PREMIER !
** Si on teste 3 d'abord, le nombre 15 afficherait "fizz" au lieu de "fizzbuzz"
** -> Toujours tester la condition la plus specifique en premier.
**
** ATTENTION: tout en MINUSCULE: fizz, buzz, fizzbuzz (pas Fizz, Buzz...)
*/
#include <unistd.h>

/*
** put_num - affiche un entier positif caractere par caractere avec write()
** Parametre n: le nombre a afficher
**
** Principe de la recursion:
** - decimal = "0123456789" : un tableau de chars ou decimal[0]='0', decimal[1]='1'...
** - Pour n=42: on appelle put_num(4) d'abord -> affiche '4'
**              puis on affiche decimal[42 % 10] = decimal[2] = '2'
** - Pour n=100: put_num(10) -> put_num(1) -> affiche '1', affiche '0', affiche '0'
*/
void	put_num(int n)
{
	char	*decimal;  /* Tableau de caracteres pour convertir chiffre -> ASCII */

	decimal = "0123456789";
	if (n > 9)
		put_num(n / 10);        /* Appel recursif pour afficher les chiffres de gauche d'abord */
	write(1, &decimal[n % 10], 1);  /* Affiche le dernier chiffre (unites) */
}

int	main(void)
{
	int	i;  /* Compteur: va de 1 a 100 inclus */

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)       /* i % 15 == 0 signifie que i est divisible par 15 (donc par 3 ET 5) */
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)  /* i % 3 == 0 signifie divisible par 3 mais PAS par 5 (car teste apres) */
			write(1, "fizz", 4);
		else if (i % 5 == 0)  /* i % 5 == 0 signifie divisible par 5 mais PAS par 3 */
			write(1, "buzz", 4);
		else
			put_num(i);        /* Ni fizz ni buzz -> afficher le nombre lui-meme */
		write(1, "\n", 1);    /* Chaque nombre/mot sur sa propre ligne */
		i++;
	}
	return (0);
}
