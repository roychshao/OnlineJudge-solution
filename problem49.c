#include <stdio.h>

int main()
{
	int x,y,move;
	char cmd;
	scanf("%c",&cmd);
	getchar();
	scanf("%c%d",&cmd,&move);
	x = move;
	getchar();
	scanf("%c%d",&cmd,&move);
	y = move;
	getchar();
	while(scanf("%c",&cmd) != 'E')
	{
		scanf("%d",&move);
		switch(cmd)
		{
			case 'U':
			{
				y += move;
				break;
			}
			case 'D':
			{
				y -= move;
				break;
			}
			case 'R':
			{
				x += move;
				break;
			}
			case 'L':
			{
				x -= move;
				break;
			}
			default:
			{
				printf("WRONG INPUT OF COMMAND!\n");
				break;
			}
		}
	}
	printf("%d\n%d\n",x,y);
	return 0;
}

