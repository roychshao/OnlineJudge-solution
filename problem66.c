#include <stdio.h>

int main()
{
	long long n;
	while(scanf("%lld",&n) != EOF)
	{
		int counter = 1;
		int record = 1;
		while(n/10 >= 10)
		{
			n /= 10;
			counter++;
		}

