#include <stdio.h>

int main()
{
	int quan;
	int nums[1000];
	scanf("%d",&quan);
	for(int i=0;i<quan;++i)
	{
		scanf("%d",&nums[i]);
	}
	for(int i=quan-1;i>=0;--i)
	{
		printf("%d ",nums[i]);
	}
	return 0;
}
