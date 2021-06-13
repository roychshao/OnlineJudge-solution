#include <stdio.h>
#include <string.h>
#define EVAL 10000000

void sort(int *queue,int index)
{
	int temp;
	for(int i=0;i<index;++i)
	{
		temp = queue[i];
		queue[i] = queue[i+1];
		queue[i+1] = temp;
	}
}	

int main()
{
	int times,ennum,i = 0;
	int queue[2000];
	int index = 0;;
	char cmd[8];
	scanf("%d",&times);
	for(int j=0;j<2000;++j)
		queue[j] = EVAL;
	while(i < times)
	{
		memset(cmd,NULL,sizeof(cmd));
		scanf("%s",cmd);
		if(cmd[0] == 'e')
		{
			scanf("%d",&ennum);
			queue[index] = ennum;
			index++;
		}
		else
		{
			if(queue[0] != EVAL)
				printf("%d\n",queue[0]);
			else
			{
				printf("empty\n");
				i++;
				continue;	//	continue or break.
			}
			queue[0] = EVAL;
			sort(queue,index);
			index--;
		}
		i++;
	}
	return 0;
}
