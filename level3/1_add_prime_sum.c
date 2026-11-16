/*
** add_prime_sum
**
** Programme qui prend un entier positif N et affiche
** la somme de tous les nombres premiers de 2 a N inclus,
** suivi d un \n.
**
** Usage:  ./add_prime_sum 5
** Output: 10   (2+3+5)
**
** Usage:  ./add_prime_sum 7
** Output: 17   (2+3+5+7)
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

int ft_atoi(char *str)
{
    int i;
    int nbr;

    i = 0;
    nbr = 0;

    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (1);
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return (nbr);
}

int is_prime(int n)
{
    int i;

    if (n < 2)
        return (0);
    i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main (int argc, char **argv)
{
    int nbr;
    int sum;
    int i;

    sum = 0;
    if (argc == 2)
    {
        nbr = ft_atoi(argv[1]);
        i = 2;
        while (i <= nbr)
        {
            if (is_prime(i))
                sum = sum + i;
            i++;
        }
    }
    ft_putnbr(sum);
    write (1, "\n", 1);
    return (0);
}