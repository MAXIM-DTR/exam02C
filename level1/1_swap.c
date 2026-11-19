/*
** ft_swap - échange les valeurs pointées par a et b
** Allowed: aucune
*/

void	ft_swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
// pas oublier les pointeur 