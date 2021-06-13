#include <stdio.h>
#include <string.h>

struct r
{
	int x;
	int y;
	int drct;
};

typedef struct r Robot;

char board[100][100];
Robot robot;

void turn(char move)
{
	if (move == 'R')
		robot.drct -= 90;
	else
		robot.drct += 90;
	if (robot.drct == 360)
		robot.drct = 0;
	if (robot.drct < 0)
		robot.drct = 270;
}

void go(int fob)
{
	if (robot.drct == 0)
		robot.x += fob;
	else if (robot.drct == 90)
		robot.y += fob;
	else if (robot.drct == 180)
		robot.x -= fob;
	else if (robot.drct == 270)
		robot.y -= fob;
}

int main()
{
	int xSize, ySize, LOST = 0;
	char command[100] = { NULL };
	char temp;
	scanf("%d%d", &xSize, &ySize);
	memset(board,NULL,sizeof(board));
	while (scanf("%d", &robot.x) != EOF)
	{
		scanf("%d", &robot.y);
		scanf(" ");
		scanf("%c", &temp);
		if (temp == 'N')
			robot.drct = 90;
		else if (temp == 'S')
			robot.drct = 270;
		else if (temp == 'E')
			robot.drct = 0;
		else
			robot.drct = 180;
		scanf("%s",command);
		LOST = 0;
		int len = strlen(command);
		for (int i = 0; i < len; ++i)
		{
			if (command[i] == 'R')
				turn('R');
			else if (command[i] == 'L')
				turn('L');
			else if (command[i] == 'F')
			{
				if (board[robot.x][robot.y] == '1')
				{
					go(1);
					if (robot.x > xSize || robot.y > ySize || robot.x < 0 || robot.y < 0)
						go(-1);
				}
				else
					go(1);
			}
			if (robot.x > xSize || robot.y > ySize || robot.x < 0 || robot.y < 0)
			{
				LOST = 1;
				go(-1);
				board[robot.x][robot.y] = '1';
				break;
			}
		}
		printf("%d %d ", robot.x, robot.y);
		if (robot.drct == 0)
			printf("E");
		else if (robot.drct == 90)
			printf("N");
		else if (robot.drct == 180)
			printf("W");
		else
			printf("S");
		if (LOST)
			printf(" LOST");
		printf("\n");
	}
	return 0;
}
