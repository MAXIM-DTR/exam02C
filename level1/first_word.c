#include <unistd.h>

void ft_first_word(char *str)
{
    int i;
    
    i = 0;
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
        i++;
    while (str[i] && str[i] != ' ' && !(str[i] >= 9 && str[i] <= 13))
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main (int argc, char **argv)
{
    if (argc != 2)
        write (1, "\n", 1);
    else
    {
        ft_first_word(argv[1]);
        write (1, "\n", 1);
    }
    return (0);
}