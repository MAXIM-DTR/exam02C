/*
** reverse_bits - inverse les bits d'un octet
** Ex: 00100110 → 01100100
** Allowed: aucune
*/


unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = (result << 1) | (octet & 1); // décale result, prend le bit 0 d'octet
		octet >>= 1;    // octet avance vers le bit suivant
		i++;
	}
	return (result);
}
