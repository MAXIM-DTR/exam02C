/*
** tab_mult - affiche la table de multiplication de N de 1 a 9
** Format attendu: "i x N = resultat\n"
** Ex pour N=9: "1 x 9 = 9", "2 x 9 = 18" ... "9 x 9 = 81"
**
** Helpers necessaires:
** - put_str: affiche une string char par char avec write
** - put_nbr: affiche un entier (recursif, comme ft_putnbr)
** - ft_atoi: convertit argv[1] (string) en int pour les calculs
*/
#include <unistd.h>

/* put_str - affiche une string avec write (pour les " x " et " = " du format) */
void	put_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* ft_atoi simplifie - pas de signe ni whitespace car le sujet dit arg toujours valide */
int	ft_atoi(char *str)
{
	int	result;
	int	i;

	i = 0;
	if (str[i] == '-')
		return (0);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

/* put_nbr - affiche un entier positif avec write (recursif) */
void	put_nbr(int n)
{
	char	*decimal;

	decimal = "0123456789";
	if (n > 9)
	{
		put_nbr(n / 10);   /* Afficher d'abord les chiffres de gauche */
		put_nbr(n % 10);   /* Puis le dernier chiffre */
	}
	else if (n < 10)
		write(1, &decimal[n], 1);  /* Chiffre simple: afficher directement */
}

/* tab_mult - affiche la table de mult de mult, de 1*mult a 9*mult */
void	tab_mult(int mult)
{
	int	i;  /* Le multiplicateur: va de 1 a 9 */

	i = 1;
	while (i < 10)
	{
		put_nbr(i);        /* Afficher "i" */
		put_str(" x ");    /* Afficher " x " */
		put_nbr(mult);     /* Afficher "mult" */
		put_str(" = ");    /* Afficher " = " */
		put_nbr(i * mult); /* Afficher le resultat */
		put_str("\n");     /* Fin de ligne */
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	else
		write(1, "\n", 1);  /* Pas d'argument: afficher seulement \n */
	return (0);
}
