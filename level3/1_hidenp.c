/*
** hidenp
**
** Programme qui prend deux strings.
** Affiche 1 si chaque char de s1 apparait dans s2
** dans le meme ordre (pas forcement consecutifs),
** affiche 0 sinon. Suivi de \n.
**
** Usage:  ./hidenp "faya" "fqhqnayacvtcba"
** Output: 1
*/

#include <unistd.h>

int main (int argc, char **argv)
{
    int i;
    int j;

    if (argc == 3)
    {
        i = 0;
        j = 0;
        while (argv[1][i] && argv[2][j])
        {
            if (argv[1][i] == argv[2][j])
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
            write (1, "1\n", 2);
        else
            write(1, "0\n", 2);
    }
    else
        write (1, "\n", 1);
    return (0);
}
