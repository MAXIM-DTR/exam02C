/*
** swap_bits - échange les deux moitiés d'un octet
** Ex: 01000001 → 00010100
** Allowed: aucune
*/


unsigned char	swap_bits(unsigned char octet)
{
	// << 4 : monte les 4 bits bas en haut | >> 4 : descend les 4 bits hauts en bas
	return ((octet << 4) | (octet >> 4));
}
