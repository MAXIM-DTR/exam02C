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

	i = 7;
	while (i >= 0)
	{
		bit = ((octet >> i) & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}
