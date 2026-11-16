/* print_bits - affiche la representation binaire d'un octet
** On teste chaque bit du plus significant (bit 7) au moins (bit 0)
** Pour tester le bit i: (octet >> i) & 1 */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i;
	char	bit;

	i = 7;  /* Bit 7 = le plus a gauche (most significant) */
	while (i >= 0)
	{
		if ((octet >> i) & 1)
			bit = '1';
		else
			bit = '0';
		write(1, &bit, 1);
		i--;
	}
}
