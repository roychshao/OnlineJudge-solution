#include <stdio.h>

int main()
{
	char input[1000000];
	int i=0;
	gets(input);
	while(input[i]!='\0')
	{
		if(input[i] == 'A')
			printf("U");
		else if(input[i] == 'T')
			printf("A");
		else if(input[i] == 'C')
			printf("G");
		else if(input[i] == 'G')
			printf("C");
		i++;
	}
	return 0;
}

