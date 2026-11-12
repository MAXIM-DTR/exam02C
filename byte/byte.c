#include <stdio.h>

int	main(void)
{
	unsigned char	n;

	n = 8;                          // 10 = 00001010

	printf("%d\n", n & 1);           // regarde la lampe de droite
	printf("%d\n", n >> 1);          // fait glisser d'une case
	printf("%d\n", (n >> 1) & 1);    // glisse d'une case, PUIS regarde la lampe de droite
	return (0);
}