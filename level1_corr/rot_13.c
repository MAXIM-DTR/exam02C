/*
** rot_13 - decale chaque lettre de 13 positions dans l'alphabet (chiffrement Caesar)
** Rot13 est son propre inverse: appliquer rot13 deux fois = texte original
**
** Formule: nouvelle_lettre = (lettre - base + 13) % 26 + base
** - (lettre - base): ramener a 0-25 (position dans l'alphabet)
** - + 13: decaler de 13
** - % 26: revenir au debut si on depasse z/Z (wrap-around)
** - + base: revenir dans la bonne plage ASCII ('a' ou 'A')
** Ex: 'a' -> (0 + 13) % 26 + 'a' = 13 + 'a' = 'n'
** Ex: 'z' -> (25 + 13) % 26 + 'a' = 12 + 'a' = 'm'
*/
#include <unistd.h>

char	*rot_13(char *str)
{
	int	i;  /* Index courant dans la string */

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = ((str[i] - 'A' + 13) % 26) + 'A';  /* Majuscule: base = 'A' */
		else if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = ((str[i] - 'a' + 13) % 26) + 'a';  /* Minuscule: base = 'a' */
		/* Les non-lettres ne sont pas modifiees */
		write(1, &str[i], 1);  /* Afficher le char (modifie ou non) */
		i++;
	}
	return (str);  /* Retourner le pointeur vers le debut (convention) */
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot_13(argv[1]);
	write(1, "\n", 1);
	return (0);
}
