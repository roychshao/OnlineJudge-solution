#include <stdio.h>

int list[1000];
int length[1000];

int max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int N,ans = 0;;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%d",&list[i]);
		length[i] = 1;
	}
	for(int i=0;i<N;++i)
	{
		for(int j=i+1;j<N;++j)
		{
			if(list[j] > list[i])
				length[j] = max(length[j],length[i]+1);
		}
	}
	for(int i=0;i<N;++i)
		ans = max(ans,length[i]);
	printf("%d\n",ans);
	return 0;
}



