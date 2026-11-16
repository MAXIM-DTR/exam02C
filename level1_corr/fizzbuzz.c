/* fizzbuzz - affiche 1 a 100
** Si multiple de 3 ET 5 -> "FizzBuzz"
** Si multiple de 3 seulement -> "Fizz"
** Si multiple de 5 seulement -> "Buzz"
** Sinon -> le nombre */
#include <unistd.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "FizzBuzz\n", 9);
		else if (i % 3 == 0)
			write(1, "Fizz\n", 5);
		else if (i % 5 == 0)
			write(1, "Buzz\n", 5);
		else
		{
			ft_putnbr(i);
			write(1, "\n", 1);
		}
		i++;
	}
	return (0);
}
