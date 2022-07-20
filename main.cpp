#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

void add(char *name1, char *name2)
{
	FILE *fp1 = fopen(name1, "r");
	FILE *fp2 = fopen(name2, "r");

	uint32_t *fst, *scd;
	uint32_t a, b, c;

	fst = (uint32_t *)malloc(2);
	scd = (uint32_t *)malloc(2);

	fread(fst, 1, 4, fp1);
	fread(scd, 1, 4, fp2);

	a = ntohl(*fst);
	b = ntohl(*scd);
	c = a + b;

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)", a, a, b, b, c, c);
}

int main(int argc, char **argv)
{
	add(argv[1], argv[2]);
	return 0;
}
