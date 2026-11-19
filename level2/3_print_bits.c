/*
** print_bits - affiche un octet en binaire (sans newline)
** Ex: print_bits(2) → "00000010"
** Allowed: write
*/

#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int		i;
	char	bit;

	i = 7;              // on commence par le bit le plus fort (MSB)
	while (i >= 0)
	{
		// (octet >> i) met le bit i en position 0, & 1 garde seulement ce bit
		bit = ((octet >> i) & 1) + '0';  // 0 → '0', 1 → '1'
		write(1, &bit, 1);
		i--;
	}
}
