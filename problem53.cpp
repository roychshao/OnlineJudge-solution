#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef struct info
{
    int x;
    int y;
    int step;
}Info;

queue<Info> que;
char map[100][100];
int x = 0, y = 0;

int BFS(int x, int y)
{
    while (!que.empty())
        que.pop();
    Info temp;
    que.push({ x,y,0 });
    while (!que.empty())
    {
        temp = que.front();
        if (map[temp.x][temp.y] == '@')
        {
            return temp.step;
        }
        map[temp.x][temp.y] = '#';
        if (map[temp.x + 1][temp.y] != '#')  que.push({ temp.x + 1,temp.y,temp.step + 1 });
        if (map[temp.x][temp.y + 1] != '#')  que.push({ temp.x,temp.y + 1,temp.step + 1 });
        if (map[temp.x - 1][temp.y] != '#')  que.push({ temp.x - 1,temp.y,temp.step + 1 });
        if (map[temp.x][temp.y - 1] != '#')  que.push({ temp.x,temp.y - 1,temp.step + 1 });
        que.pop();
    }
    return -1;
}

void findK(int n)
{
    int i ,j,find = 0;
    int len = strlen(map[0]);
    for (i = 0; i < n; ++i)
    {
        for (j = 0; j < len; ++j)
        {
            if (map[i][j] == 'K')
            {
                find = 1;
                x = i, y = j;
                break;
            }
        }
        if (find)    
            break;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n == 0)  break;
        memset(map, 0, sizeof(map));
        for (int i = 0; i < n; ++i)
            cin >> map[i];
        findK(n);
        int ans = BFS(x, y);
        if (ans == -1)
            cout << "= =" << '"' << endl;
        else
            cout << ans << endl;
    }
    return 0;
}
