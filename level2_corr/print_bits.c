/*
** print_bits - affiche les 8 bits d'un octet en binaire, sans newline
** Ex: print_bits(2) -> "00000010" (2 en binaire = 00000010)
**
** Technique: decalage de bits
** Pour extraire le bit i d'un octet:
** - Decaler l'octet de i positions vers la droite: octet >> i
** - Garder seulement le bit de poids faible: & 1
** - (octet >> i) & 1 = 1 si le bit i est 1, 0 si le bit i est 0
** On ajoute '0' pour obtenir le char ASCII '0' ou '1'
**
** On commence par le bit 7 (poids fort) pour afficher de gauche a droite
*/
#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char	bit;  /* Le bit courant a afficher ('0' ou '1') */
	int				i;    /* Compteur: 7 a 0 (bit de poids fort a faible) */

	i = 8;  /* Commence a 8 car on decremente AVANT d'utiliser (i-- donne 7, 6...0) */
	while ((i--) > 0)
	{
		/* (octet >> i): decaler l'octet de i positions vers la droite
		** & 1: garder seulement le dernier bit (0 ou 1)
		** + '0': convertir en char ASCII ('0' ou '1') */
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}
