#include <stdio.h>

int a[1000000],b[1000000];

int main()
{
	int aSize,bSize;
	int aIndex = 0,bIndex = 0;
	scanf("%d",&aSize);
	for(int i=0;i<aSize;++i)
		scanf("%d",&a[i]);
	scanf("%d",&bSize);
	for(int i=0;i<bSize;++i)
		scanf("%d",&b[i]);	
	while(aIndex != aSize || bIndex != bSize)
	{
		if(aIndex == aSize && bIndex != bSize)
		{
			printf("%d ",b[bIndex]);
			bIndex++;
		}
		else if(bIndex == bSize && aIndex != aSize)
		{
			printf("%d ",a[aIndex]);
			aIndex++;
		}
		else if(a[aIndex] <= b[bIndex])
		{
			printf("%d ",a[aIndex]);
			aIndex++;
		}
		else if(b[bIndex] < a[aIndex])
		{
			printf("%d ",b[bIndex]);
			bIndex++;
		}
	}
	return 0;
}


