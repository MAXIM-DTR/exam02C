/* fprime - affiche les facteurs premiers
** Ex: 225 -> 3*3*5*5, 12 -> 2*2*3
** Methode: essayer de diviser par i depuis 2
** Si n % i == 0 -> i est un facteur, diviser n par i
** Sinon incrementer i */
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	n;
	int	i;
	int	first;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		i = 2;
		first = 1;
		if (n == 1)
			write(1, "1", 1);
		else
		{
			while (n > 1)
			{
				if (n % i == 0)  /* i est un facteur */
				{
					if (!first)
						write(1, "*", 1);
					ft_putnbr(i);
					n /= i;      /* Diviser pour trouver les suivants */
					first = 0;
				}
				else
					i++;  /* i n'est pas un facteur, essayer le suivant */
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}
