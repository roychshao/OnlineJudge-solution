#include <stdio.h>
#include <string.h>

int main()
{
	int i=0,n,index=50;
	char command[10];
	int stack[2051];
	memset(stack,-1,sizeof(stack));
	scanf("%d",&n);
	while(i<n)
	{
		scanf("%s",command);
		if(strcmp(command,"push") == 0)
		{
			scanf("%d",&stack[index]);
			index++;
		}
		else if(strcmp(command,"pop") == 0)
		{
			if(stack[index-1] < 0)
			{
				printf("empty\n");
				memset(command,NULL,sizeof(command));
				index--;
			}
			else
			{
				printf("%d\n",stack[index-1]);
				stack[index-1] = -1;
				memset(command,NULL,sizeof(command));
				index--;
			}
		}
		i++;
	}
	return 0;
}
