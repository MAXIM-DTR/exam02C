/* reverse_bits - inverse les bits d'un octet
** Le bit 0 devient bit 7, bit 1 devient bit 6, etc.
** Methode: construire le resultat en prenant les bits de droite a gauche */
#include <unistd.h>

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;
	int			i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = result << 1;         /* Faire de la place a droite */
		result = result | (octet & 1); /* Mettre le bit 0 de octet dans result */
		octet = octet >> 1;           /* Passer au bit suivant de octet */
		i++;
	}
	return (result);
}
