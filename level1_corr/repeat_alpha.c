/*
** repeat_alpha - repete chaque lettre N fois (N = rang dans l'alphabet)
** a est la 1ere lettre (rang 1), b la 2eme (rang 2)... z la 26eme (rang 26)
** Meme logique pour les majuscules: A=1, B=2... Z=26
** Les non-lettres sont affichees telles quelles (1 seule fois)
**
** Formule pour le rang:
** - Minuscule: rang = str[i] - 'a' + 1  (car 'a' - 'a' = 0, donc +1 pour commencer a 1)
** - Majuscule: rang = str[i] - 'A' + 1
** Ex: 'a' - 'a' + 1 = 1, 'b' - 'a' + 1 = 2, 'z' - 'a' + 1 = 26
*/
#include <unistd.h>

/*
** ft_putchar - affiche un char 'c' exactement 'times' fois
** Parametres: c = le char a afficher, times = combien de fois l'afficher
*/
void	ft_putchar(char c, int times)
{
	while (times > 0)
	{
		write(1, &c, 1);  /* Ecrire le char sur stdout */
		times--;           /* Decrementer jusqu'a 0 */
	}
}

void	repeat_alpha(char *str)
{
	int	i;     /* Index courant dans la string */
	int	rank;  /* Rang de la lettre dans l'alphabet (1 a 26) */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			rank = str[i] - 'A' + 1;  /* 'A'=1, 'B'=2 ... 'Z'=26 */
			ft_putchar(str[i], rank);  /* Afficher str[i] exactement rank fois */
		}
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			rank = str[i] - 'a' + 1;  /* 'a'=1, 'b'=2 ... 'z'=26 */
			ft_putchar(str[i], rank);
		}
		else
			write(1, &str[i], 1);  /* Non-lettre: afficher une seule fois */
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
	return (0);
}
