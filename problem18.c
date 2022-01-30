#include <stdio.h>
#include <string.h>

int main()
{
	int times, i = 0, idx, num;
	int bnry[32];
	scanf("%d", &times);
	while(i < times)
	{
		idx = 0;
		memset(bnry, 0, sizeof(bnry));
		scanf("%d", &num);
		if(num == 0)
		{
			printf("0\n");
			continue;
		}
		while(num > 0)
		{
			if(num % 2)
			{
				num = (num - 1) / 2;
				bnry[idx++] = 1;
			}
			else
				num /= 2, bnry[idx++] = 0;
		}
		for(int j = idx-1;j >= 0; --j)
			printf("%d",bnry[j]);
		printf("\n");
		i++;
	}
	return 0;
}
