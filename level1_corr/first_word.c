/*
** first_word - affiche le premier mot d'une string
** Un "mot" = suite de chars qui ne sont pas des espaces ou tabs
**
** Algorithme en 2 phases:
** Phase 1 - Ignorer le debut: sauter les espaces et tabs initiaux
**           Ex: "   hello world" -> on saute jusqu'au 'h'
** Phase 2 - Afficher: lire et afficher chars jusqu'au prochain separateur
**           Ex: on affiche 'h', 'e', 'l', 'l', 'o' puis on s'arrete sur ' '
*/
#include <unistd.h>

void	first_word(char *str)
{
	int	i;  /* Index pour naviguer dans str, commence a 0 */

	i = 0;
	/* Phase 1: avancer i sans rien afficher tant qu'on est sur un separateur */
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	/* Phase 2: afficher chaque char jusqu'au prochain espace, tab ou fin de string */
	while (str[i] != ' ' && str[i] != '\t' && str[i] != '\0')
	{
		write(1, &str[i], 1);  /* write(fd=1 stdout, adresse_du_char, 1 octet) */
		i++;
	}
	/* On s'arrete ici: pas besoin d'afficher le newline, main s'en charge */
}

int	main(int argc, char **argv)
{
	/* argc = nombre d'arguments (argv[0] compte aussi)
	** argc == 2 signifie: argv[0] = programme, argv[1] = notre argument */
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);  /* Toujours afficher \n a la fin, meme si aucun argument */
	return (0);
}
