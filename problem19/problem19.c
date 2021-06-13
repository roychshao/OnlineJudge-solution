#include <stdio.h>
#include <string.h>

int main()
{
	int i = 0;
	int k = 0;
	int times = 0;
	scanf("%d",&times);
	int quan = 0;
	int input[1000];
	while(k<times)
	{
		scanf("%d",&quan);
		for (i=0;i<quan;i++)
		{
			scanf("%d",&input[i]);
		}
		for ( i=quan-1;i>0;i--)	// bubble sort
		{
			for (int j=0;j<=i-1;j++)
			{
				int tmp = 0;
				if (input[j+1]<input[j])
				{
					tmp = input[j];
					input[j] = input[j+1];
					input[j+1] = tmp;
				}
			}
		}
		for ( i=0;i<quan;i++)
		{
			printf("%d",input[i]);
			if(i==quan-1)
				break;
			printf(" ");
		}
		i = 0;
		printf("\n");
		memset(input,(int)NULL,sizeof(input));
		k++;
	}
	return 0;
}






