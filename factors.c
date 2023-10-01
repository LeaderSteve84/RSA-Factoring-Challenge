#include "factors.h"
/**
 */
void factorise(int n)
{
	int i;

	for (i = 2; i <= n / 2; i++)
	{
		if (n % i == 0)
		{
			printf("%d=%d*%d\n", n, i, n / i);
		}
	}
}
/**
 */

int main(int argc, char *argv)
{
	FILE *file;
	char buffer[100];
	int num;

	if (argc != 2)
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	
	file = fopen(argv[1], "r");
	if (file == NULL)
		perror("Error opening file");
		return (1);

	while (fgets(buffer, sizeof(buffer), file))
	{
		num = atoi(buffer);
		if (num <= 1)
		{
			continue;
		}
		factorise(n);
	}
	fclose(file);
	return (0);
}
