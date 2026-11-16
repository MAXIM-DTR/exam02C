/* print_bits - affiche les 8 bits d'un octet
** i commence a 8, decrement avant usage (i = 7 d'abord)
** (octet >> i & 1) isole le bit i, +  '0' donne '0' ou '1' */
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	i = 8;
	while ((i--) > 0)
	{
		result = (octet >> i & 1) + '0';
		write(1, &result, 1);
	}
}
