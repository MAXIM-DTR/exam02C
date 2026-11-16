#include <unistd.h>

int main (int argc, char **argv)
{
	int i;

	while (argv[1][i] == ' ' || argv[1][i] == '\t')
		i++;
	while (argv[1][i] && argv[1][i] != ' ' || argv[1][i] != '\t')
	{
		write (1, &argv[1][i], 1);
		i++;
	}
}
