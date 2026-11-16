/* paramsum - somme tous les arguments
** Convertir chaque argv en int avec atoi et additionner
** Si argc == 1 (aucun arg), afficher 0 */
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr(int n)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;
	int	sum;

	sum = 0;
	i = 1;
	while (i < argc)
	{
		sum += atoi(argv[i]);
		i++;
	}
	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
