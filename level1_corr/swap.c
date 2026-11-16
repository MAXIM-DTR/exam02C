/* ft_swap - echange les valeurs de deux entiers
** Utilise une variable temporaire (pas de magie) */
#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;   /* Sauvegarder la valeur de a */
	*a = *b;     /* a prend la valeur de b */
	*b = temp;   /* b prend l'ancienne valeur de a */
}
