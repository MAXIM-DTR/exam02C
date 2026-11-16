/*
** expand_str
**
** Programme qui prend une string et l affiche
** en remplacant chaque espace par 10 espaces.
**
** Usage:  ./expand_str "1 2  3"
** Output: "1          2          3"
*/
#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int first;

    if (argc == 2)
    {
        i = 0;
        first = 1;
        while (argv[1][i])
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] && !first)
                write (1, "          ", 10);
            while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                write (1, &argv[1][i], 1);
                first = 0;
                i++;
            }
        }
    }
    write (1, "\n", 1);
    return (0);
}