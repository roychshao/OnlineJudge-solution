#include <stdio.h>

void change(int *grade,int a,int b)
{
	int temp;
	temp = grade[a-1];
	grade[a-1] = grade[b-1];
	grade[b-1] = temp;
}

int main()
{
	int stu_quan,cmd_quan;
	int i,grade[100],a,b;
	scanf("%d",&stu_quan);
	for(i=0;i<stu_quan;++i)
	{
		scanf("%d",&grade[i]);
	}
	scanf("%d",&cmd_quan);
	i = 0;
	while(i<cmd_quan)
	{
		scanf("%d%d",&a,&b);
		change(grade,a,b);
		i++;
	}
	for(i=0;i<stu_quan;++i)
	{
		printf("%d ",grade[i]);
	}
	return 0;
}



