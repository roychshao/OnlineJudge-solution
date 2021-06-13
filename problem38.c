#include <stdio.h>
#include <string.h>

char words[1001][100];

int main()
{
	int i=0,j,k;
	char temp[100];
	while(scanf("%s",words[i]) != EOF)
		i++;
	for(j=i-1;j>0;j--)
	{
		for(k=0;k<i-1;++k)
		{
			if(strcmp(words[k],words[k+1]) > 0)
			{
				strcpy(temp,words[k]);
				strcpy(words[k],words[k+1]);
				strcpy(words[k+1],temp);
			}
		}
	}
	for(j=0;j<i;++j)
		puts(words[j]);
	return 0;
}
	
