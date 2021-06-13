#include <stdio.h>
#include <string.h>

int main()
{
	int i=0,times,flag = 0;
	int aIndex,bIndex,oIndex,oSize,counter;
	char a[40] = { 0 },b[40] = { 0 };
	char output[40] = { 0 };
	scanf("%d",&times);
	while(i < times)
	{
		scanf("%s",a);
		scanf("%s",b);
		memset(output,NULL,sizeof(output));
		aIndex = strlen(a)-1;
		bIndex = strlen(b)-1;
		oIndex = oSize = counter = 0;
		if(aIndex <= bIndex)
		{
			flag = 0;
			oIndex = aIndex;
			oSize = bIndex + 1;
		}
		else
		{
			flag = 1;
			oIndex = bIndex;
			oSize = aIndex + 1;
		}
		while(oIndex >= 0)
		{
			int temp;
			temp = (int)(a[aIndex--]-'0') + (int)(b[bIndex--]-'0');
			if(counter)
				temp++;
			if(temp >= 10)
			{
				temp -= 10;
				counter = 1;
			}
			else
				counter = 0;
			output[oSize--] = (char)(temp + 48);	//	ASCII '0' = 48.
			oIndex--;
		}
		while(aIndex >= 0)
		{
			int temp = (int)(a[aIndex]-'0');
			if(counter)
				temp++;
			if(temp >= 10)
			{
				temp -= 10;
				counter = 1;
			}
			else
				counter = 0;
			output[oSize--] = (char)(temp + 48);
			aIndex--;
		}	
		while(bIndex >= 0)
		{
			int temp = (int)(b[bIndex]-'0');
			if(counter)
				temp++;
			if(temp >= 10)
			{
				temp -= 10;
				counter = 1;
			}
			else
				counter = 0;
			output[oSize--] = (char)(temp + 48);
			bIndex--;
		}
		if(counter)
			output[oSize] = '1';
		if(!flag)
			oSize = strlen(b);
		else
			oSize = strlen(a);
		for(int j=0;j<=oSize;++j)
		{
			if(output[j] != NULL)
				printf("%c",output[j]);
		}
		printf("\n");
		i++;
	}
	return 0;
}
