/* do_op - operation arithmetique
** IMPORTANT: utilise printf (pas write)
** Args: nombre1 operateur nombre2 */
#include <stdio.h>
#include <stdlib.h>

int	do_op(int a, char op, int b)
{
	int	result;

	result = 0;
	if (op == '*')
		result = a * b;
	else if (op == '+')
		result = a + b;
	else if (op == '-')
		result = a - b;
	else if (op == '/')
		result = a / b;
	else if (op == '%')
		result = a % b;
	return (result);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		printf("%i", do_op(atoi(argv[1]), argv[2][0], atoi(argv[3])));
	printf("\n");
	return (0);
}
