/* ft_swap - echange deux entiers via pointeurs
** temp sert a ne pas perdre la valeur de *a */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
