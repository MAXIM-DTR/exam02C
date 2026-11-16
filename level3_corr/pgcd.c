/* pgcd (PGCD) - Plus Grand Commun Diviseur
** Algorithme d'Euclide: pgcd(a, b) = pgcd(b, a % b)
** Quand b == 0, le resultat est a
** Ex: pgcd(12, 8): 12%8=4, pgcd(8,4): 8%4=0, pgcd(4,0)=4 */
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(unsigned int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	temp;

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		/* Algorithme d'Euclide iteratif */
		while (b)
		{
			temp = b;
			b = a % b;
			a = temp;
		}
		ft_putnbr(a);
	}
	write(1, "\n", 1);
	return (0);
}
