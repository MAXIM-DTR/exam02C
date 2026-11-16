/*
** epur_str
**
** Programme qui prend une string et l affiche en:
** - reduisant les espaces multiples a un seul espace
** - supprimant les espaces en debut et fin de string
** Suivi d un \n.
**
** Usage:  ./epur_str "  hello   world  "
** Output: "hello world"
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int first_l;

    if (argc == 2)
    {
        i = 0;
        first_l = 1;
        while (argv[1][i])
        {
            while (argv[1][i] == ' ' || argv[1][i] == '\t')
                i++;
            if (argv[1][i] && !first_l)
                write (1, " ", 1);
            while (argv[1][i] && (argv[1][i] != ' ' || argv[1][i] != ' '))
            {
                write (1, &argv[1][i], 1);
                first_l = 0;
                i++;
            }
        }
        write (1, "\n", 1);
    }
    return (0);
}