/* reverse_bits - inverse les bits d'un octet
** result * 2 = decaler a gauche d'un bit
** octet % 2 = prendre le bit de droite de octet
** octet / 2 = passer au bit suivant */

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int				i;

	i = 8;
	result = 0;
	while (i-- > 0)
	{
		result = result * 2 + (octet % 2);
		octet = octet / 2;
	}
	return (result);
}
