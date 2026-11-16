/* add_prime_sum - somme des nombres premiers jusqu'a N
** Pour chaque nombre de 2 a N, verifier s'il est premier
** (divisible par aucun nombre entre 2 et n-1)
** Additionner tous les premiers trouves */
#include <unistd.h>
#include <stdlib.h>

int	is_prime(int n)
{
	int	i;

	if (n < 2)
		return (0);
	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return (0);  /* Divisible -> pas premier */
		i++;
	}
	return (1);
}

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
	int	sum;

	if (argc == 2)
	{
		n = atoi(argv[1]);
		sum = 0;
		i = 2;
		while (i <= n)
		{
			if (is_prime(i))
				sum += i;
			i++;
		}
		ft_putnbr(sum);
	}
	write(1, "\n", 1);
	return (0);
}
