#include <stdio.h>
#include <string.h>

char a[1000001];
char b[1000001];
char c[2000002];

int main()
{
	int i = 0,j = 0;
	int a_size = 0;
	int b_size = 0;
	scanf("%d",&a_size);
	for (i = 0;i < a_size;i++)
	{
		scanf("%c",&a[i]);
	}
	scanf("%d",&b_size);
	for (i = 0;i < b_size;i++)
	{
		scanf("%c",&b[i]);
	}
   	strcpy(c,a);
	strcpy(c,b);
	int size = a_size + b_size;
	// bubble sort
	for (i=size-1;i>0;i--)
	{
		for (j=0;j<=i-1;j++)
		{
			char tmp = NULL;
			if (c[j+1]<c[j])
			{
				tmp = c[j];
				c[j] = c[j+1];
				c[j+1] = tmp;
			}
		}
	}
	for (i = 0;i < size;i++)
	{
		printf("%c",c[i]);
		if (i == size-1)
			break;
		printf(" ");
	}
	printf("\n");
	return 0;
}
				






