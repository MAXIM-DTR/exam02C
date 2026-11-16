/* epur_str - nettoie les espaces superflus
** Supprimer leading/trailing spaces, reduire espaces multiples a un seul
** Methode: "look-ahead" - on n'imprime un espace que s'il y a du texte apres */
#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;
	int	last_was_space;

	if (argc == 2)
	{
		i = 0;
		last_was_space = 1;  /* Commence a 1 pour ignorer les espaces du debut */
		while (argv[1][i])
		{
			if (argv[1][i] == ' ')
			{
				if (!last_was_space)
				{
					/* Verifier s'il y a du texte apres cet espace */
					int j = i + 1;
					while (argv[1][j] == ' ')
						j++;
					if (argv[1][j])  /* Il y a du texte -> imprimer l'espace */
						write(1, " ", 1);
					last_was_space = 1;
				}
			}
			else
			{
				write(1, &argv[1][i], 1);
				last_was_space = 0;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
