/*
** union - affiche les chars des deux strings sans doublons
** L'affichage respecte l'ordre d'apparition dans la ligne de commande
** (d'abord tous les chars de s1, puis de s2, en sautant les deja affiches)
**
** Probleme: comment savoir si un char a deja ete affiche?
** Solution: tableau seen[256] - un entier par valeur ASCII possible (0-255)
** seen[c] = 0 : le char c n'a pas encore ete affiche
** seen[c] = 1 : le char c a deja ete affiche -> sauter
**
** On initialise tout a 0 puis on met a 1 chaque char affiche
*/
#include <unistd.h>

/*
** print_union - affiche les chars de str qui ne sont pas encore dans seen
** Parametre seen: tableau partage entre les deux appels pour tracker les doublons
*/
void	print_union(char *str, int *seen)
{
	int	i;  /* Index courant dans str */

	i = 0;
	while (str[i])
	{
		if (!seen[(unsigned char)str[i]])  /* Ce char n'a pas encore ete affiche */
		{
			seen[(unsigned char)str[i]] = 1;  /* Marquer comme vu */
			write(1, &str[i], 1);             /* Afficher */
		}
		/* Si deja vu: on passe simplement au suivant */
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	seen[256];  /* Tableau de 256 cases (une par valeur ASCII possible) */
	int	i;          /* Compteur pour initialiser seen */

	/* Initialiser tout le tableau a 0 (aucun char vu au depart) */
	i = 0;
	while (i < 256)
		seen[i++] = 0;
	if (argc == 3)
	{
		print_union(argv[1], seen);  /* D'abord afficher les chars de argv[1] */
		print_union(argv[2], seen);  /* Puis les chars de argv[2] pas encore vus */
	}
	write(1, "\n", 1);
	return (0);
}
