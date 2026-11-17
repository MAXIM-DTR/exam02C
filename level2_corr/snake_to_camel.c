/*
** snake_to_camel - convertit snake_case en lowerCamelCase
** Ex: here_is_a_snake_case_word -> hereIsASnakeCaseWord
** Ex: hello_world -> helloWorld
**
** Principe: quand on rencontre un '_', on le saute ET on met la lettre
** SUIVANTE en majuscule (- 32 en ASCII)
** Le premier mot reste entierement en minuscule
*/
#include <unistd.h>

void	snake_to_camel(char *str)
{
	char	c;  /* Le char transforme a afficher */
	int		i;  /* Index courant dans str */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '_' && str[i + 1] != '\0')
		{
			/* On a trouve un '_' suivi d'un char valide */
			c = str[i + 1] - 32;  /* Mettre la lettre suivante en majuscule (-32 ASCII) */
			write(1, &c, 1);
			i += 2;  /* Sauter A LA FOIS le '_' ET la lettre qui suit */
		}
		else
		{
			write(1, &str[i], 1);  /* Char normal: afficher tel quel */
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		snake_to_camel(av[1]);
	write(1, "\n", 1);
	return (0);
}
