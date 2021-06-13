#include <stdio.h>

int main()
{
	int i=0,times,year;
	scanf("%d",&times);
	while(i<times)
	{
		scanf("%d",&year);
		if((year%4==0 && year%100!=0) ||
		   (year%400==0))
			printf("Happy Birthday!\n");
		else
			printf("QAQ\n");
		i++;
	}
	return 0;
}
