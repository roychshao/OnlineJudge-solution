#include <stdio.h>

int main()
{
	int n,max,ans;
	int nums[100000];
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%d",&nums[i]);
	max = nums[0];
	ans = nums[0] - nums[1];
	for(int i=0;i<n;++i)
	{
		if(nums[i] > max)
			max = nums[i];
		else if(max - nums[i] > ans)
			ans = max - nums[i];
	}
	printf("%d\n",ans);
	return 0;
}
