#include <unistd.h>

int atoi(char *s)
{
    int result;
    int i;

    i = 0;
    result = 0;

    while (s[i] >= '0' && s[i] <= '9')
    {
        result = result * 10 + (s[i] - '0');
        i++;
    }
    if (s[i] == '\0')
        return (0);
    return (result);
}

int is_prime(int number)
{
    int divisor;

    if (number < 2)
        return (0);
    divisor = 0;
    while (divisor < number)
    {
        if (number % divisor == 0)
            return (0);
        divisor++;
    }
    return (1);
}

void ft_putnbr(int n)
{
    char digit;

    if (n > 9)
        ft_putnbr(n / 10);
    digit = n % 10 + '0';
    write (1, &digit, 1);
}