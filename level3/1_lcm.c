/*
** lcm
**
** Programme qui prend deux entiers non signes et affiche
** leur PPCM (Plus Petit Commun Multiple), suivi de \n.
**
** PPCM = (a * b) / PGCD(a, b)
**
** Usage:  ./lcm 4 6
** Output: 12
*/

unsigned int    lcm(unsigned int a, unsigned int b)
{
    unsigned int mult;

    if (a == 0 || b == 0)
        return (0);
    mult = a;
    while (mult % b != 0)
    {
        mult = mult + a; 
    }
    return (mult);
}