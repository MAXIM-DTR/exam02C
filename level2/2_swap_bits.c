/*
** swap_bits - échange les deux moitiés d'un octet
** Ex: 01000001 → 00010100
** Allowed: aucune
*/


unsigned char	swap_bits(unsigned char octet)
{
	return ((octet << 4) | (octet >> 4));
}
