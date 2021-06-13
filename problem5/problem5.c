#include <stdio.h>
#include <string.h>

int main()
{
	char input[1001];
	int times = 0;
	int i = 0;
	int j;
	int len = 0;
	scanf("%d\n",&times);
	
	while(i<times)
	{
		gets(input);
		if((int)strlen(input)%2==0)
			len = (int)strlen(input)/2;	
		else
			len = ((int)strlen(input)+1)/2;
		for(j=0;j<len;j++)
		{
			char tmp=NULL;
			tmp = input[j];
			input[j] = input[strlen(input)-j-1];
			input[strlen(input)-j-1] = tmp;
		}
		printf("%s\n",input);
		i++;
	}
	return 0;
}


