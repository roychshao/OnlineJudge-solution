#include <stdio.h>
#include <string.h>

int main()
{
	int times,i=0;
	int bindex;
	char bnry[32];
	scanf("%d",&times);
	while(i < times)
	{
		int num;
		bindex = 0;	
		memset(bnry,NULL,sizeof(bnry));		
		scanf("%d",&num);
		if(num == 0)
		{
			printf("0\n");
			i++;
			continue;
		}
		while(num > 0)
		{
			if(num % 2 == 0)
			{
				num /= 2;
				bnry[bindex] = '0';
				bindex++;
			}
			else
			{
				num = (num - 1) / 2;
				bnry[bindex] = '1';
				bindex++;
			}
		}
		for(int j=bindex-1;j>=0;j--)
			printf("%c",bnry[j]);
		printf("\n");
		i++;
	}
	return 0;
}
