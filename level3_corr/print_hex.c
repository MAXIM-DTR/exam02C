/*
** print_hex - affiche un entier positif (ou 0) en hexadecimal minuscule
** Hexadecimal = base 16: chiffres 0-9 puis lettres a-f
** Ex: 10 -> "a", 255 -> "ff", 5156454 -> "4eae66"
**
** Methode recursive (comme ft_putnbr mais en base 16):
** - base = "0123456789abcdef" : tableau de 16 chars, un par valeur 0-15
** - base[n % 16] donne le char hex du dernier chiffre
** - Appel recursif sur n/16 pour afficher les chiffres de gauche d'abord
**
** Exemple: n=255
** 255 >= 16 -> appel recursif(15) -> 15 >= 16? non -> affiche base[15] = 'f'
** Puis affiche base[255%16] = base[15] = 'f'
** Resultat: "ff" ✓
*/
#include <unistd.h>

void	print_hex(unsigned int n)
{
	char	*base;  /* "0123456789abcdef": chaque position correspond a sa valeur hex */

	base = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);  /* Afficher d'abord les chiffres hex de gauche */
	write(1, &base[n % 16], 1);  /* Puis afficher le dernier chiffre hex */
}

/*
** ft_atoi simple: convertit seulement les chiffres (pas de signe ni whitespace)
** Car le sujet dit "entier positif ou zero"
*/
int	ft_atoi(char *str)
{
	int	i;    /* Index courant */
	int	nbr;  /* Nombre accumule */

	i = 0;
	nbr = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
