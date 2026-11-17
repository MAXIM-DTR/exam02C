/*
** reverse_bits - inverse tous les bits d'un octet
** Ex: 00100110 -> 01100100
**
** Technique: construire le resultat bit par bit
** On lit les bits de l'octet de droite a gauche (poids faible en premier)
** et on les place dans result de gauche a droite (poids fort en premier)
**
** A chaque iteration:
** - result * 2 (ou result <<1): decale result d'un bit vers la gauche (fait de la place)
** - octet % 2 (ou octet & 1): extrait le bit de poids faible de octet
** - octet / 2 (ou octet >> 1): passe au bit suivant de octet
*/

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char	result;  /* Le resultat construit bit par bit */
	int				i;       /* Compteur de 8 iterations (un par bit) */

	i = 8;
	result = 0;  /* Commence a 0 (tous les bits a 0) */
	while (i-- > 0)
	{
		result = result * 2 + (octet % 2);
		/* result * 2: decale tous les bits de result vers la gauche d'1 position */
		/* octet % 2: extrait le dernier bit de octet (0 ou 1) */
		/* octet / 2: on passe au bit suivant en divisant par 2 (decalage droite) */
		octet = octet / 2;
	}
	return (result);
}
