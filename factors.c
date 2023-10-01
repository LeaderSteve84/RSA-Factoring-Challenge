#include "factors.h"
/**
 * gcd - function to calculate the greatest common divisor
 * (gcd) of two number.
 * @a: integer a
 * @b:integer b
 * Return: integer
 */
int64_t gcd(int64_t a, int64_t b)
{
	if (b == 0)
	{
		return (a);
	}
	return (gcd(b, a % b));
}
/**
 * pollards_rho - pollands rho algoritm for factorization
 * @n: number
 * Return: integer value
 */
int64_t pollards_rho(int64_t n)
{
	int64_t x = 2, y = 2, d = 1;

	while (d == 1)
	{
		x = (x * x + 1) % n;
		y = (y * y + 1) % n;
		y = (y * y + 1) % n;
		d = gcd(labs(x - y), n);
	}
	return (d);
}
/**
 * factorise - function to factorise a number n and print
 * its factorization
 * @n: numbere
 * Retuen: Nothing
 */
void factorise(int64_t n)
{
	int64_t factor;

	if (n <= 1)
	{
		return;
	}

	if (n % 2 == 0)
	{
		printf("%ld=%ld * 2\n", n, n / 2);
		return;
	}

	factor = pollards_rho(n);
	if (factor == n)
	{
		printf("%ld=%ld*1\n", n, n);
	}
	else
	{
		printf("%ld=%ld*%ld\n", n, n / factor, factor);
	}
}

/**
 * main - entry point
 * @argc: argument count
 * @argv: argument vector
 * Return: (0) integer
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char buffer[100];
	long int num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fgets(buffer, sizeof(buffer), file))
	{
		num = atol(buffer);
		if (num <= 1)
		{
			continue;
		}
		factorise(num);
	}
	fclose(file);
	return (0);
}
