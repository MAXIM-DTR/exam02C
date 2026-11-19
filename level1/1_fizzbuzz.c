/*
** fizzbuzz - affiche les nombres de 1 à 100 avec les règles FizzBuzz
** multiple de 3: "fizz" | multiple de 5: "buzz" | multiple de 15: "fizzbuzz"
** sinon: le nombre. Un résultat par ligne.
** Allowed: write
*/

#include <unistd.h>

void ft_putnbr (int nbr)
{
	char c;
	if (nbr >= 10) // condition >= 10
		ft_putnbr(nbr / 10);
	c = nbr % 10 + '0';
	write (1, &c, 1);
}
void ft_fizzbuzz(void) //void i c le int   
{
	int i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write (1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write (1, "fizz", 4);
		else if (i % 5 == 0)
			write (1, "buzz", 4);
		else
			ft_putnbr(i);
			write (1, "\n", 1);
		i++;
	}
}
int	main(void)
{
	ft_fizzbuzz();
	return (0);
}
