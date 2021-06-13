#include <stdio.h>

int min(int A,int B,int C,int D)
{
	int temp = A;
	if(B < temp)
		temp = B;
	if(C < temp)
		temp = C;
	if(D < temp)
		temp = D;
	return temp;
}

int main()
{
	int times,i=0;
	int n,m,k;
	int A,B,C,D;
	int score = 0;
	//	n * students.
	//	m * testcase quan
	//	k * score per testcase.
	char testcases[100][100];
	scanf("%d",&times);
	while(i < times)
	{
		score = 0;
		scanf("%d%d%d",&n,&m,&k);
		for(int j=0;j<n;++j)
		{
			getchar();
			scanf("%s",testcases[j]);
		}
		for(int s=0;s<m;++s)
		{
			A = B = C = D = 0;
			for(int t=0;t<n;++t)
			{
				if(testcases[t][s] == 'A')
					A++;
				else if(testcases[t][s] == 'B')
					B++;
				else if(testcases[t][s] == 'C')
					C++;
				else if(testcases[t][s] == 'D')
					D++;
			}
			score += min(A,B,C,D) * k;
		}
		printf("%d\n",score);
		i++;
	}
	return 0;
}		
