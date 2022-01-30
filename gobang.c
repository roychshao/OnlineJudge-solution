
/*************************
*	計分方式如下:			 *
*	全活1: 16, 一邊被擋-2	 *
*	死2: 16				 *
*	2空1: 500,			 *
*	活2 , 死3: 100		 *
*	活3 , 死4: 1000	 	 *
*	活4 : 10000		 	 *
*	五子一線: 999999		 *
**************************/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define LIVE1 16
#define DEATH2 16
#define HALFTWOANDONE 80
#define LIVE2 100
#define DEATH3 100
#define TWOANDONE 500
#define LIVE3 1000
#define ALLDEATH4 0
#define HALFDEATH4 9999
#define THREEANDONE 9900
#define LIVE4 10000
#define FIVESCORE 9999999
#define GAMEOVERSCORE 9990000
#define SUBTRACT 2
#define WHITECHESS 1
#define BLACKCHESS -1
#define NOCHESS 0
#define DEFENDCOEFFICIENT 100


int chess[15][15];
int chesscopy[15][15];
int chessscore[15][15];
int ComputerScore = 0;
int PlayerScore = 0;
bool gameover = false;

void print()
{
	/* 印出棋盤 */
	for (int i = 14; i >= 0; --i)
	{
		if (i + 1 < 10)
			printf("%d ", 1 + i);
		else if (1 + i == 10)	printf("A ");
		else if (1 + i == 11)	printf("B ");
		else if (1 + i == 12)	printf("C ");
		else if (1 + i == 13)	printf("D ");
		else if (1 + i == 14)	printf("E ");
		else if (1 + i == 15)	printf("F ");
		for (int j = 0; j < 15; ++j)
		{
			if (chess[i][j] == 0)
				printf(". ");
			else if (chess[i][j] == 1)
				printf("O ");
			else if (chess[i][j] == -1)
				printf("X ");
		}
		printf("\n");
	}
	printf("  1 2 3 4 5 6 7 8 9 A B C D E F\n\n");
}

void Initialize()
{
	memset(chess, NOCHESS, sizeof(chess));
	memset(chessscore, NOCHESS, sizeof(chessscore));
	srand(time(NULL));
	/* 設定棋盤靠中央的分數較高，四周較低 */
	for(int i = 0;i < 15; ++i)
		for (int j = 0; j < 15; ++j)
		{
			if (i <= 7)
				chessscore[i][j] += i;
			else
				chessscore[i][j] += 14 - i;
		}
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (j <= 7)
				chessscore[i][j] += j;
			else
				chessscore[i][j] += 14 - j;
		}
	}
	puts("**************************************");
	puts("*             GAME START             *");
	puts("**************************************\n");
	puts("WHITE CHESS GO FIRST !!\n");
	print();
}

int CalScore(int codename)
{
	int length = 0, score = 0, i_cp, j_cp;
	int oppo = -1 * codename;
	/* 橫向組合 */
	memcpy(chesscopy, chess, sizeof(chess));
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			i_cp = i, j_cp = j, length = 0;
			while (j_cp < 15 && chesscopy[i_cp][j_cp] == codename)
			{
				chesscopy[i_cp][j_cp] = 0;
				length++, j_cp++;
			}
			/* 算分 */
			if ((length == 2 && (j == 0 || chess[i][j - 1] == oppo || j_cp == 15 || chess[i][j_cp] == oppo)))
			{
				if ((j_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
					(j > 1 && chess[i][j - 1] == NOCHESS && chess[i][j - 2] == codename))
					score += HALFTWOANDONE;
				else
					score += DEATH2;
			}
			else if (length == 2 && j != 0 && j_cp != 15 && chess[i][j - 1] != oppo && chess[i][j_cp] != oppo)
			{
				if ((j_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
					(j > 1 && chess[i][j - 1] == NOCHESS && chess[i][j - 2] == codename))
					score += TWOANDONE;
				else
					score += LIVE2;
			}
			else if (length == 3 && ((j_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
				(j > 1 && chess[i][j - 1] == NOCHESS && chess[i][j - 2] == codename)))
				score += THREEANDONE;
			else if (length == 3 && (j == 0 || chess[i][j - 1] == oppo || j_cp == 15 || chess[i][j_cp] == oppo))
				score += DEATH3;
			else if (length == 3 && j != 0 && j_cp != 15 && chess[i][j - 1] != oppo && chess[i][j_cp] != oppo)
				score += LIVE3;
			else if (length == 4 && ((j == 0 || chess[i][j-1] == oppo) && (j_cp == 15 || chess[i][j_cp] == oppo)))
				score += ALLDEATH4;
			else if (length == 4 && (j == 0 || chess[i][j - 1] == oppo || j_cp == 15 || chess[i][j_cp] == oppo))
				score += HALFDEATH4;
			else if (length == 4 && j != 0 && j_cp != 15 && chess[i][j - 1] != oppo && chess[i][j_cp] != oppo)
				score += LIVE4;
			else if (length >= 5)
				score += FIVESCORE;
		}
	}
	/* 縱向組合 */
	memcpy(chesscopy, chess, sizeof(chess));
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			i_cp = i, j_cp = j, length = 0;
			while (i_cp < 15 && chesscopy[i_cp][j_cp] == codename)
			{
				chesscopy[i_cp][j_cp] = 0;
				length++, i_cp++;
			}
			if (length == 2 && (i == 0 || chess[i - 1][j] == -oppo || i_cp == 15 || chess[i_cp][j] == oppo))
			{
				if ((i_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
					(i > 1 && chess[i - 1][j] == NOCHESS && chess[i - 2][j] == codename))
					score += HALFTWOANDONE;
				else
					score += DEATH2;
			}
			else if (length == 2 && i != 0 && i_cp != 15 && chess[i - 1][j] != oppo && chess[i_cp][j] != oppo)
			{
				if ((i_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
					(i > 1 && chess[i - 1][j] == NOCHESS && chess[i - 2][j] == codename))
					score += TWOANDONE;
				else
					score += LIVE2;
			}
			else if (length == 3 && ((i_cp < 14 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp][j_cp + 1] == codename) ||
				(i > 1 && chess[i - 1][j] == NOCHESS && chess[i - 2][j] == codename)))
				score += THREEANDONE;
			else if (length == 3 && (i == 0 || chess[i - 1][j] == oppo || i_cp == 15 || chess[i_cp][j] == oppo))
				score += DEATH3;
			else if (length == 3 && i != 0 && i_cp != 15 && chess[i - 1][j] != oppo && chess[i_cp][j] != oppo)
				score += LIVE3;
			else if (length == 4 && ((i == 0 || chess[i-1][j] == oppo) && (i_cp == 15 || chess[i_cp][j] == oppo)))
				score += ALLDEATH4;
			else if (length == 4 && (i == 0 || chess[i - 1][j] == oppo || i_cp == 15 || chess[i_cp][j] == oppo))
				score += HALFDEATH4;
			else if (length == 4 && i != 0 && i_cp != 15 && chess[i - 1][j] != oppo && chess[i_cp][j] != oppo)
				score += LIVE4;
			else if (length >= 5)
				score += FIVESCORE;
		}
	}
	/* 遞減方向組合 */
	memcpy(chesscopy, chess, sizeof(chess));
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			i_cp = i, j_cp = j, length = 0;
			while (j_cp >= 0 && i_cp < 15 && chesscopy[i_cp][j_cp] == codename)
			{
				chesscopy[i_cp][j_cp] = 0;
				length++, j_cp--, i_cp++;
			}
			if (length == 2 && (j_cp == -1 || i_cp == 15 || j == 14 || i == 0 || chess[i_cp][j_cp] == oppo || chess[i - 1][j + 1] == oppo))
			{
				if ((i_cp < 15 && j_cp > 0 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp - 1] == codename) ||
					(i > 1 && j < 14 && chess[i - 1][j + 1] == NOCHESS && chess[i - 2][j + 2] == codename))
					score += HALFTWOANDONE;
				else
					score += DEATH2;
			}
			else if (length == 2 && (j_cp != -1 && i_cp != 15) && (j != 14 && i != 0) && chess[i_cp][j_cp] != oppo && chess[i - 1][j + 1] != oppo)
			{
				if ((i_cp < 15 && j_cp > 0 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp - 1] == codename) ||
					(i > 1 && j < 14 && chess[i - 1][j + 1] == NOCHESS && chess[i - 2][j + 2] == codename))
					score += TWOANDONE;
				else
					score += LIVE2;
			}
			else if (length == 3 && ((i_cp < 15 && j_cp > 0 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp - 1] == codename) ||
				(i > 1 && j < 14 && chess[i - 1][j + 1] == NOCHESS && chess[i - 2][j + 2] == codename)))
				score += THREEANDONE;
			else if (length == 3 && (j_cp == -1 || i_cp == 15 || j == 14 || i == 0 || chess[i_cp][j_cp] == oppo || chess[i - 1][j + 1] == oppo))
				score += DEATH3;
			else if (length == 3 && (j_cp != -1 && i_cp != 15) && (j != 14 && i != 0) && chess[i_cp][j_cp] != oppo && chess[i - 1][j + 1] != oppo)
				score += LIVE3;
			else if (length == 4 && (((j == 14 && i == 0) || chess[i - 1][j + 1] == oppo) && ((j_cp == -1 && i_cp == 15) || chess[i_cp][j_cp] == oppo)))
				score += ALLDEATH4;
			else if (length == 4 && (j_cp == -1 || i_cp == 15 || j == 14 || i == 0 || chess[i_cp][j_cp] == oppo || chess[i - 1][j + 1] == oppo))
				score += HALFDEATH4;
			else if (length == 4 && (j_cp != -1 && i_cp != 15) && (j != 14 && i != 0) && chess[i_cp][j_cp] != oppo && chess[i - 1][j + 1] != oppo)
				score += LIVE4;
			else if (length >= 5)
				score += FIVESCORE;
		}
	}
	/* 遞增方向組合 */
	memcpy(chesscopy, chess, sizeof(chess));
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			i_cp = i, j_cp = j, length = 0;
			while (i_cp < 15 && j_cp < 15 && chesscopy[i_cp][j_cp] == codename)
			{
				chesscopy[i_cp][j_cp] = 0;
				length++, j_cp++, i_cp++;
			}
			if (length == 2 && (i == 0 || j == 0 || i_cp == 15 || j_cp == 15 || chess[i - 1][j - 1] == oppo || chess[i_cp][j_cp] == oppo))
			{
				if ((i_cp < 15 && j_cp < 15 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp + 1] == codename) ||
					(i > 1 && j > 1 && chess[i - 1][j - 1] == NOCHESS && chess[i - 2][j - 2] == codename))
					score += HALFTWOANDONE;
				else
					score += DEATH2;
			}
			else if (length == 2 && (i != 0 && j != 0) && (i_cp != 15 && j_cp != 15) && chess[i - 1][j - 1] != oppo && chess[i_cp][j_cp] != oppo)
			{
				if ((i_cp < 15 && j_cp < 15 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp + 1] == codename) ||
					(i > 1 && j > 1 && chess[i - 1][j - 1] == NOCHESS && chess[i - 2][j - 2] == codename))
					score += TWOANDONE;
				else
					score += LIVE2;
			}
			else if (length == 3 && ((i_cp < 15 && j_cp < 15 && chess[i_cp][j_cp] == NOCHESS && chess[i_cp + 1][j_cp + 1] == codename) ||
				(i > 1 && j > 1 && chess[i - 1][j - 1] == NOCHESS && chess[i - 2][j - 2] == codename)))
				score += THREEANDONE;
			else if (length == 3 && (i == 0 || j == 0 || i_cp == 15 || j_cp == 15 || chess[i - 1][j - 1] == oppo || chess[i_cp][j_cp] == oppo))
				score += DEATH3;
			else if (length == 3 && (i != 0 && j != 0) && (i_cp != 15 && j_cp != 15) && chess[i - 1][j - 1] != oppo && chess[i_cp][j_cp] != oppo)
				score += LIVE3;
			else if (length == 4 && ((i == 0 && j == 0) || chess[i - 1][j - 1] == oppo) && ((i_cp == 15 && j_cp == 15) || chess[i_cp][j_cp] == oppo))
				score += ALLDEATH4;
			else if (length == 4 && (i == 0 || j == 0 || i_cp == 15 || j_cp == 15 || chess[i - 1][j - 1] == oppo || chess[i_cp][j_cp] == oppo))
				score += HALFDEATH4;
			else if (length == 4 && (i != 0 && j != 0) && (i_cp != 15 && j_cp != 15) && chess[i - 1][j - 1] != oppo && chess[i_cp][j_cp] != oppo)
				score += LIVE4;
			else if (length >= 5)
				score += 9999999;
		}
	}
	/* 單子分 */
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (chess[i][j] == codename)
			{
				if ((i == 0 || chess[i - 1][j] != codename) &&
					(i == 0 || j == 14 || chess[i - 1][j + 1] != codename) &&
					(j == 14 || chess[i][j + 1] != codename) &&
					(i == 14 || j == 14 || chess[i + 1][j + 1] != codename) &&
					(i == 14 || chess[i + 1][j] != codename) &&
					(i == 14 || j == 0 || chess[i + 1][j - 1] != codename) &&
					(j == 0 || chess[i][j - 1] != codename) &&
					(i == 0 || j == 0 || chess[i - 1][j - 1] != codename))
					score += (LIVE1 + chessscore[i][j]);
				else
					continue;
				if (i == 0 || chess[i - 1][j] == oppo)
					score -= SUBTRACT;
				if (i == 0 || j == 14 || chess[i - 1][j + 1] == oppo)
					score -= SUBTRACT;
				if (j == 14 || chess[i][j + 1] == oppo)
					score -= SUBTRACT;
				if (i == 14 || j == 14 || chess[i + 1][j + 1] == oppo)
					score -= SUBTRACT;
				if (i == 14 || chess[i + 1][j] == oppo)
					score -= SUBTRACT;
				if (i == 14 || j == 0 || chess[i + 1][j - 1] == oppo)
					score -= SUBTRACT;
				if (j == 0 || chess[i][j - 1] == oppo)
					score -= SUBTRACT;
				if (i == 0 || j == 0 || chess[i - 1][j - 1] == oppo)
					score -= SUBTRACT;
			}
		}
	}
	return score;
}

void ComputerMove(int x, int y)
{
	int best_i = 0, best_j = 0, cstemp = 0, pstemp = 0, StateScore = -100000;
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			if (chess[i][j] == NOCHESS)	/* 對每一步可能的走法做算分 */
			{
				chess[i][j] = BLACKCHESS;
				cstemp = CalScore(BLACKCHESS);
				pstemp = CalScore(WHITECHESS);
				chess[i][j] = NOCHESS;
				if (StateScore <= ((cstemp - ComputerScore) + DEFENDCOEFFICIENT * (PlayerScore - pstemp)))	/* 更新最佳走法 */
				{
					int RandNum = rand() % 2;	/* 設定亂數讓電腦在兩個同分的位置任選 */
					if (StateScore == ((cstemp - ComputerScore) + DEFENDCOEFFICIENT * (PlayerScore - pstemp)) && RandNum)
						break;
					best_i = i, best_j = j;
					StateScore = (cstemp - ComputerScore) + (PlayerScore - pstemp);
					ComputerScore = cstemp, PlayerScore = pstemp;
				}
			}
		}
	}
	chess[best_i][best_j] = BLACKCHESS;
	printf("(Computer) Black chess on %d %d.\n", best_j + 1, best_i + 1);
	print();
}


int main()
{
	int counter = 0, x, y;
	Initialize();
	while (!gameover)
	{
		printf("ROUND %d:\n", counter+1);
		if (counter % 2 == 0)	/* 玩家下棋 */
		{
			printf("(Player) Enter the place you are going to put on:");
			scanf("%d%d", &x, &y);
			if (x > 15 || y > 15 || x < 1 || y < 1 || chess[y-1][x-1] != 0)	/* 不能下的位置 */
			{
				printf("Wrong step !!\n");
				printf("(Player) Enter the place you are going to put on:");
				scanf("%d%d", &x, &y);
			}
			chess[y-1][x-1] = WHITECHESS;
			print();
			PlayerScore = CalScore(1);
		}
		else	/* 電腦下棋 */
			ComputerMove(x, y);
		if (PlayerScore >= GAMEOVERSCORE)	/* 遊戲結束判定 */
		{
			printf("The white chess win !! (Player)\n");
			gameover = true;
			break;
		}
		else if (ComputerScore >= GAMEOVERSCORE)
		{
			printf("The black chess win !! (Computer)\n");
			gameover = true;
			break;
		}
		//printf("PlayerScore is: %d\nComputerScore is: %d\n", PlayerScore, ComputerScore);
		counter++;
	}
	return 0;
}