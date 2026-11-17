/*
** ft_strlen - retourne la longueur d'une string (nombre de chars avant '\0')
** Parametre str: la string dont on veut la longueur
**
** '\0' est le terminateur de string en C, il n'est PAS compte dans la longueur
** Ex: ft_strlen("hello") = 5, ft_strlen("") = 0
*/

int	ft_strlen(char *str)
{
	int	len;  /* Compteur: nombre de chars vus jusqu'ici */

	len = 0;
	/* Incrementer len pour chaque char qui n'est pas '\0' */
	while (str[len] != '\0')
		len++;  /* str[len] passe au char suivant a chaque iteration */
	/* Quand on sort de la boucle, len = position du '\0' = longueur de la string */
	return (len);
}
