#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N,val,ans = -1000000,choose;
	map<int,int>::iterator iter;
	cin >> N;
	map<int,int>coins;
	for(int i=0;i<N;++i)
	{
		cin >> val;
		iter = coins.find(val);
		if(iter != coins.end())
			iter->second += val;
		else
			coins.insert(pair<int,int>(val,val));
	}
	for(map<int,int>::iterator it = coins.begin();it != coins.end();++it)
	{
		if(it->second > ans)
		{
			choose = it->first;
			ans = it->second;
		}
	}
	if(choose > 0)
		printf("%d\n%d0000\n",choose,ans);
	else
		printf("0\n0\n");
	return 0;
}
	
