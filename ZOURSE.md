# Repeat Alpha - Examen 42

Le projet **repeat_alpha** est un exercice classique des examens de l'école 42. L'objectif est de créer un programme qui prend une chaîne de caractères en paramètre et affiche chaque lettre un nombre de fois égal à sa position dans l'alphabet.

---

## 💻 Code Source Complet (Corrigé et Validé)

Voici le code propre, respectant la logique attendue à l'examen :

```c
#include <unistd.h>

int	main(int ac, char **av)
{
	int	i;
	int	repeat;

	// 1. Vérification du nombre d'arguments (Le binaire + 1 chaîne de caractères)
	if (ac == 2)
	{
		i = 0;
		// 2. Parcours de la chaîne de caractères caractère par caractère
		while (av[1][i] != '\0')
		{
			// Par défaut, un caractère non-alphabétique s'affiche 1 fois
			repeat = 1;

			// 3. Calcul du nombre de répétitions pour les minuscules
			if (av[1][i] >= 'a' && av[1][i] <= 'z')
				repeat = av[1][i] - 'a' + 1;

			// 4. Calcul du nombre de répétitions pour les majuscules
			else if (av[1][i] >= 'A' && av[1][i] <= 'Z')
				repeat = av[1][i] - 'A' + 1;

			// 5. Affichage du caractère le nombre de fois requis
			while (repeat > 0) 
			{
				write(1, &av[1][i], 1);
				repeat--;
			}
			i++;
		}
	}
	// 6. Affichage du retour à la ligne final réglementaire
	write(1, "\n", 1);
	return (0);
}
```

---

## 🔬 Décryptage Détaillé du Code

### 1. La gestion des arguments : `if (ac == 2)`
* `ac` (Argument Count) contient le nombre de paramètres passés au programme.
* `av[0]` est toujours le nom de ton programme (ex: `./repeat_alpha`).
* `av[1]` est la chaîne de caractères que l'utilisateur donne en entrée.
* Si l'utilisateur n'écrit rien ou donne trop d'arguments, le programme saute directement à la fin pour afficher uniquement un retour à la ligne `\n`.

### 2. Le parcours de la chaîne : `while (av[1][i] != '\0')`
* `av[1]` est un pointeur vers notre chaîne. Pour lire chaque lettre, on utilise un index `i`.
* On avance lettre par lettre (`av[1][0]`, `av[1][1]`, etc.) tant qu'on n'a pas atteint le caractère nul `'\0'` qui symbolise la fin de la chaîne en C.

### 3. La formule magique : `repeat = av[1][i] - 'a' + 1`
En informatique, les lettres sont de simples nombres (codes ASCII). Elles se suivent dans l'ordre. On utilise cette propriété pour calculer leur position :

* **La soustraction (`lettre - 'a'`)** : Calcule la distance entre la lettre actuelle et la lettre 'a'.
  * Si la lettre est `'a'` (97 en ASCII) : `97 - 97 = 0`.
  * Si la lettre est `'b'` (98 en ASCII) : `98 - 97 = 1`.
  * Si la lettre est `'z'` (122 en ASCII) : `122 - 97 = 25`.
* **L'ajustement (`+ 1`)** : Comme le calcul commence à 0, on ajoute 1 pour obtenir le vrai nombre de répétitions souhaité (`'a'` = 1 fois, `'b'` = 2 fois, etc.).

### 4. La boucle d'affichage : `while (repeat > 0)`
* `write(1, &av[1][i], 1);` : Écrit le caractère actuel sur la sortie standard (l'écran).
* `repeat--;` : Décrémente le compteur de 1 à chaque passage.
* La boucle s'arrête dès que le caractère a été écrit le nombre de fois requis.

---

## 🚀 Exemple de fonctionnement

Si on lance le programme avec `"Abc"` :
* `'A'` : Détecté comme majuscule $\rightarrow$ `('A' - 'A' + 1)` = 1. Affichage : `A`
* `'b'` : Détecté comme minuscule $\rightarrow$ `('b' - 'a' + 1)` = 2. Affichage : `bb`
* `'c'` : Détecté comme minuscule $\rightarrow$ `('c' - 'a' + 1)` = 3. Affichage : `ccc`

Résultat final dans le terminal : `Abbccc`
