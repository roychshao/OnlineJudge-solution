#include <stdio.h>
#include <string.h>

int main()
{
	int times = 0;
	int i = 0;
	char input[1001];
	char c;
	scanf("%d\n",&times);
	while(i<times)
	{
		scanf(" ");
		gets(input);
		c = getchar();
		for(int j=0;j<strlen(input);j++)
		{
			if(input[j] != c)
				printf("%c",input[j]);
		}
		printf("\n");
		i++;
	}
	return 0;
}

