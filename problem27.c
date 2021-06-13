#include <stdio.h>
#include <string.h>

// reverse it and finished.

void reverse(char *record)
{
	for(int i=strlen(record)-1;i>=0;--i)
	{
		printf("%c",record[i]);
	}
}	

int main()
{
	int times,i=0;
	scanf("%d",&times);
	while(i<times)
	{
		int n,half_len;
		scanf("%d",&n);
		half_len = n;
		if(n < 26)
			n += 26;
		char letter = (char)(((n-26)%26)+64);
		char record[100] = {NULL};
		int s,t,rindex=0;
		for(s=0;s<half_len;++s)
		{
			if(n == 26)
				letter = 'Z';
			if(record[0] != NULL)
				printf("%s",record);
			for(t=rindex;t<half_len;++t)
			{
				printf("%c",letter);
			}
			for(t=rindex;t<half_len-1;++t)
			{
				printf("%c",letter);
			}
			reverse(record);
			printf("\n");
			record[rindex] = letter;
			rindex++;
			n--;
			if(n < 26)
				n += 26;
			letter = (char)(((n-26)%26)+64);			
		}
		int l=1;
		rindex--;
		for(s=0;s<half_len-1;++s)
		{
			record[rindex] = NULL;
			if(record[0] != NULL)
				printf("%s",record);
			rindex--;
			for(t=0;t<l;++t)
			{
				printf("%c",record[rindex]);
			}
			l += 2;
			reverse(record);
			if(s != half_len-2)	
				printf("\n");
		}	
		i++;
	}
	return 0;
}



			
