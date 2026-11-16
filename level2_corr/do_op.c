/* do_op - effectue une operation arithmetique
** Args: nombre1 operateur nombre2
** Operateurs: + - * / % */
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
	int	a;
	int	b;
	char	op;

	if (argc == 4)
	{
		a = atoi(argv[1]);
		b = atoi(argv[3]);
		op = argv[2][0];
		if (op == '+')
			ft_putnbr(a + b);
		else if (op == '-')
			ft_putnbr(a - b);
		else if (op == '*')
			ft_putnbr(a * b);
		else if (op == '/')
			ft_putnbr(a / b);
		else if (op == '%')
			ft_putnbr(a % b);
	}
	write(1, "\n", 1);
	return (0);
}
