/*
** add_prime_sum - somme de tous les nombres premiers <= N
**
** NOMBRE PREMIER: divisible seulement par 1 et lui-meme (ex: 2, 3, 5, 7, 11...)
** 1 n'est PAS premier (par definition), 2 est le seul premier pair
**
** OPTIMISATION dans is_prime: tester les diviseurs jusqu'a sqrt(n) seulement
** Pourquoi? Si n = a * b avec a <= b, alors a <= sqrt(n)
** Donc si aucun diviseur <= sqrt(n), n est premier
** On utilise i * i <= n pour eviter d'appeler sqrt() (plus efficace)
*/
#include <unistd.h>

/*
** ft_putnbr - affiche un entier positif avec write() (recursif)
** Principe: afficher d'abord n/10 (chiffres de gauche) puis n%10 (unite)
*/
void	ft_putnbr(int n)
{
	char	c;  /* Le char du chiffre courant */

	if (n >= 10)
		ft_putnbr(n / 10);  /* Afficher d'abord tous les chiffres de gauche */
	c = n % 10 + '0';       /* Convertir le chiffre en char ASCII */
	write(1, &c, 1);
}

/*
** ft_atoi - version simple: retourne -1 si un char non-numerique est trouve
** On ne gere pas les espaces ou signes car le sujet dit "entier positif"
*/
int	ft_atoi(char *str)
{
	int	i;    /* Index courant */
	int	nbr;  /* Nombre accumule */

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);  /* Char invalide -> retourner -1 (signifie entree invalide) */
		nbr = nbr * 10 + (str[i] - '0');  /* Accumulation: ex "123" -> 1*100 + 2*10 + 3 */
		i++;
	}
	return (nbr);
}

/*
** is_prime - retourne 1 si n est premier, 0 sinon
** Cas speciaux: n < 2 (0 et 1 ne sont pas premiers)
** Boucle: tester les diviseurs de 2 jusqu'a sqrt(n) (i*i <= n)
*/
int	is_prime(int n)
{
	int	i;  /* Diviseur candidat, commence a 2 */

	if (n < 2)
		return (0);  /* 0 et 1 ne sont pas premiers */
	i = 2;
	while (i * i <= n)  /* Tester jusqu'a sqrt(n): si i*i > n, n est premier */
	{
		if (n % i == 0)
			return (0);  /* Divisible par i -> pas premier */
		i++;
	}
	return (1);  /* Aucun diviseur trouve -> n est premier */
}

int	main(int argc, char **argv)
{
	int	nbr;  /* Le N donne en argument (converti depuis la string) */
	int	sum;  /* La somme des premiers trouves */
	int	i;    /* Compteur: teste chaque nombre de 2 a N */

	sum = 0;
	if (argc == 2)
	{
		nbr = ft_atoi(argv[1]);
		i = 2;  /* Commencer a 2 (le plus petit premier) */
		while (i <= nbr)
		{
			if (is_prime(i))
				sum += i;  /* Ajouter i a la somme s'il est premier */
			i++;
		}
	}
	ft_putnbr(sum);  /* Afficher 0 si argc != 2 ou arg invalide */
	write(1, "\n", 1);
	return (0);
}
