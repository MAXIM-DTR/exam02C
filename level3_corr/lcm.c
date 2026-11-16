/* lcm (PPCM) - Plus Petit Commun Multiple
** Formule: PPCM(a, b) = a / PGCD(a, b) * b
** (division avant multiplication pour eviter l'overflow)
** PGCD avec l'algorithme d'Euclide */
#include <unistd.h>
#include <stdlib.h>

unsigned int	pgcd(unsigned int a, unsigned int b)
{
	unsigned int	temp;

	while (b)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

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

	if (argc == 3)
	{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		if (a == 0 || b == 0)
			write(1, "0", 1);
		else
			ft_putnbr((a / pgcd(a, b)) * b);
	}
	write(1, "\n", 1);
	return (0);
}
