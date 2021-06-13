#include <stdio.h>
#include <string.h>

int main()
{
	char input[1000];
	fgets(input, 1000, stdin);
	int odd = 0, even = 0;
	int len = strlen(input)-1;
	int counter = 0;
	while (counter < len)
	{
		if (counter % 2 == 0)
			odd += (int)(input[counter] - '0');
		else
			even += (int)(input[counter] - '0');
		counter++;
	}
	if (odd > even)
		printf("%d\n", odd - even);
	else
		printf("%d\n", even - odd);
	return 0;
}

