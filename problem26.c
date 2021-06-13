#include <stdio.h>
#include <string.h>
#include <ctype.h>

//	fgets will read the '\n'.

int main()
{
	char input[100],*in;
	int score,len;
	while(in = fgets(input,sizeof(input),stdin))
	{
		score = 0;
		len = strlen(input);
	   	for(int i=0;i<len-1;++i)
		{
			score += (int)tolower(input[i]);
			if(score > 100)
				score -= 100;
		}
		printf("%d\n",score);
	}
	return 0;
}

		
