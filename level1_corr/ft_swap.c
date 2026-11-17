/*
** ft_swap - echange les valeurs pointees par a et b
** Parametres: int *a et int *b (POINTEURS vers les entiers, pas les entiers eux-memes)
**
** Pourquoi des pointeurs?
** En C, les arguments sont passes par VALEUR. Si on passait des int (pas des int*),
** la fonction recevrait des copies et les modifications ne se verraient pas dehors.
** Avec des pointeurs, on accede directement a la memoire originale.
**
** Pourquoi temp?
** Sans temp: *a = *b; *b = *a; -> FAUX car apres la 1ere ligne *a est deja perdu
** Avec temp: on sauvegarde *a avant de l'ecraser
*/

void	ft_swap(int *a, int *b)
{
	int	temp;  /* Variable temporaire pour sauvegarder la valeur de *a */

	temp = *a;  /* 1. Sauvegarder la valeur a laquelle pointe a */
	*a = *b;    /* 2. a prend la valeur de b (l'ancienne valeur de a est dans temp) */
	*b = temp;  /* 3. b prend l'ancienne valeur de a (sauvegardee dans temp) */
}
