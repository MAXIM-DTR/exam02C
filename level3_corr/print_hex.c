/* print_hex - affiche un entier en hexadecimal minuscule
** Base 16: 0123456789abcdef
** Methode recursive: afficher la partie haute, puis le dernier chiffre */
#include <unistd.h>
#include <stdlib.h>

void	print_hex(unsigned int n)
{
	char	*hex;
	char	c;

	hex = "0123456789abcdef";
	if (n >= 16)
		print_hex(n / 16);  /* Afficher d'abord les chiffres plus a gauche */
	c = hex[n % 16];        /* Prendre le dernier chiffre hexadecimal */
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
