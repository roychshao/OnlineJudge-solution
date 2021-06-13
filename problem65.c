#include <stdio.h>

int nums[100000];

int main()
{
	int quan;
	scanf("%d",&quan);
	for(int i=0;i<quan;++i)
		scanf("%d",&nums[i]);
	int hindex = 0,tindex = quan-1;
	int head = nums[0],tail = nums[quan-1];
	int counter = 0;
	while(hindex < quan && tindex >= 0)
	{
		if(head > tail)
		{
			tindex--;
			tail += nums[tindex];
		}
		else if(head < tail)
		{
			hindex++;
			head += nums[hindex];
		}
		else
		{
			counter++;
			hindex++;
			tindex--;
			head += nums[hindex];
			tail += nums[tindex];
		}
	}
	printf("%d\n",counter);
	return 0;
}
