#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
	int i=0,times;
	char input[10000];
	scanf("%d",&times);
	while(i < times)
	{
		memset(input,NULL,sizeof(input));
		scanf("%s",input);
		int j,len = strlen(input);
		long long temp = 0,ans = 0;
		for(j=0;j<len;++j)
		{
			temp = 0;
			while(isdigit(input[j]))
			{
				temp = temp*10 + (long long)(input[j] - '0');
				j++;
			}
			ans += temp;
		}
		printf("%lld\n",ans);
		i++;
	}
	return 0;
}
				





