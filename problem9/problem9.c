#include <stdio.h>

int main()
{
	int input;
	scanf("%d",&input);
	while(input != 1)
	{
		printf("%d",input);
		printf(" ");
		if ((input%2)==1)
		{
			input = (3*input)+1;
		}
		else
			input = input/2;
	}
	printf("1");
	return 0;
}
