/*
** paramsum
**
** Programme qui affiche la somme de tous les arguments
** passes en entiers, suivi de \n.
** Si aucun argument, affiche 0.
**
** Usage:  ./paramsum 1 2 3 4
** Output: 10
*/
#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write (1, &c, 1);
}


int main (int argc, char **argv)
{
    (void)argv;
    ft_putnbr(argc - 1);
    write (1, "\n", 1);
    return (0);
}