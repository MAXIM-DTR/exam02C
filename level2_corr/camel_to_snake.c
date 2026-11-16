/* camel_to_snake - camelCase -> snake_case avec malloc
** IMPORTANT: si le premier char est majuscule, PAS de '_' devant
** Ex: helloWorld -> hello_world
** Ex: MyFunction -> _my_function (non), My -> my (oui)
** Le 'i != 0' evite le '_' au debut */
#include <unistd.h>
#include <stdlib.h>

int	snake_len(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z' && i != 0)
			len++;  /* +1 pour le '_' a ajouter */
		len++;
		i++;
	}
	return (len);
}

char	*camel_to_snake(char *str)
{
	char	*snake;
	int		len;
	int		i;
	int		j;

	len = snake_len(str);
	snake = (char *)malloc((len + 1) * sizeof(char));
	i = 0;
	j = 0;
	while (j <= len)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			if (i != 0)
				snake[j++] = '_';  /* Underscore avant (sauf premier char) */
			snake[j] = str[i] + 32;  /* Majuscule -> minuscule */
		}
		else
			snake[j] = str[i];
		j++;
		i++;
	}
	snake[len] = '\0';
	return (snake);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		write(1, camel_to_snake(argv[1]), snake_len(argv[1]));
	write(1, "\n", 1);
	return (0);
}
