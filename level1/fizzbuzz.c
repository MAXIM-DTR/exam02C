#include <unistd.h>

int putnb(int n)
{
    char c;

    if (n > 9)
        putnb(n / 10);
    c = (n % 10) + '0';
    write (1, &c, 1);

}

void ft_fizzbuzz()
{
    int i;
    
    i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz\n", 9);
        else if (i % 3 == 0)
            write (1, "fizz\n", 5);
        else if (i % 5 == 0)
            write (1, "buzz\n", 5);
        else
        {
            putnb(i);
            write(1, "\n", 1);
        }
        i++;
    }
}

int main ()
{
    ft_fizzbuzz();
    return (0);
}
