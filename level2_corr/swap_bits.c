/* swap_bits - echange les deux nibbles d'un octet
** Un nibble = 4 bits (moitie d'un octet)
** Partie haute (bits 4-7) <-> partie basse (bits 0-3)
** Ex: 0b01000111 -> 0b01110100
** >> 4 = partie haute vers le bas, << 4 = partie basse vers le haut */
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}
