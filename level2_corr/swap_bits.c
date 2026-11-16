/* swap_bits - echange les deux nibbles (4 bits chacun)
** >> 4 : amene la partie haute en position basse
** << 4 : amene la partie basse en position haute
** | combine les deux */

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
