#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int T, i = 0, j = 0;
int N, M;
int from, to;
int flow[2][100000];
queue<pair<int,int>> que;

int BFS()
{
	pair<int, int> temp;
	while (!que.empty())
		que.pop();
	que.push({from,0});
	while (!que.empty())
	{
		temp = que.front();
		if (from == to)
			return 0;
		for (int i = 0; i < M; ++i)
		{
			if (temp.first == flow[0][i])
			{
				if (flow[1][i] == to)
					return temp.second + 1;
				que.push({ flow[1][i],temp.second + 1 });
				flow[0][i] = NULL;
			}
		}
		que.pop();
	}
	return -1;
}

int main()
{
	int ans;
	cin >> T;
	while (i < T)
	{
		cin >> N >> M;
		cin >> from >> to;
		memset(flow, 0, sizeof(flow));
		for (int s = 0; s < M; ++s)
		{
			for (int t = 0; t < 2; ++t)
				cin >> flow[t][s];
		}
		ans = BFS();
		cout << ans << endl;
		i++;
	}
}
