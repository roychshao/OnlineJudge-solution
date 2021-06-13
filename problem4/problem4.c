#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	char dna[1000000];
	char rna[1000000];
	gets(dna);
	for (i=0;i<strlen(dna);i++)
	{
		switch(dna[i])
		{
			case 'A':
				rna[i]='U';
				break;
			case 'T':
				rna[i]='A';
				break;
			case 'C':
				rna[i]='G';
				break;
			case 'G':
				rna[i]='C';
				break;
			default:
				printf("error");
				break;
		}
	}
	printf("%s" , rna);
	return 0;
}




