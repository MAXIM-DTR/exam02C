/*
** swap_bits - echange les deux moities (nibbles) d'un octet
** Un octet = 8 bits = 2 nibbles de 4 bits chacun
** Ex: 0100|0001 -> 0001|0100
**     (nibble haut | nibble bas -> nibble bas | nibble haut)
**
** Technique avec les operateurs de bits:
** - octet >> 4: decaler l'octet de 4 bits vers la droite
**   -> amene le nibble haut en position basse (les 4 bits hauts vers les 4 bas)
** - octet << 4: decaler l'octet de 4 bits vers la gauche
**   -> amene le nibble bas en position haute
** - | (OR): combiner les deux pour former l'octet final
**
** Ex: octet = 01000001 (0x41)
** >> 4 = 00000100 (nibble haut -> position basse)
** << 4 = 00010000 (nibble bas -> position haute)
** OR  = 00010100 (combine) ✓
*/

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
	/* octet >> 4: nibble haut vers le bas */
	/* octet << 4: nibble bas vers le haut */
	/* | : fusion des deux nibbles inverses */
}
