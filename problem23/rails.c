#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int location(int *arr,int j)
{
	int i,loc,temp = 0;
	for(i=0;i<j;++i)
	{
		if(arr[i]>temp)
		{
			temp = arr[i];
			loc = i;
		}
	}
	return loc;
}

int check_head(int *station)
{
	int i=0;
	while(1)
	{
		if(station[i]!=(-1))
			return station[i];
		else
			i++;
	}
}

int large(int *arr,int elements)
{
	int i,temp = 0;
	for(i=0;i<elements;++i)
	{
		if(arr[i]>temp)
			temp = arr[i];
	}
	return temp;
}

int exist(int *arr,int aim,int elements)
{
	int i,flag = 0;
	for(i = 0;i<elements;++i)
	{
		if(arr[i] == aim)
			flag = 1;
	}
	return flag;
}

int main()
{
	int i = 0,elements = 0,j_cp;
	int sta_counter = 0;
	int input[1000000] = {-1};
	int station[1000000] = {-1};
	int loc,large_num,NIE_instructor = 0;
	while(scanf("%d",&elements) != EOF)
	{
		for(i=0;i<elements;++i)
		{
			scanf("%d",&input[i]);
		}
		for(int k=0;k<elements;++k)
		{
			loc = location(input,elements); 	// loc point to the largest place.
			large_num = large(input,elements); 	// the largest data.
			sta_counter = 0;
			for(j_cp=loc;j_cp<elements;++j_cp)
			{
				if(input[j_cp]>0)
				{
					station[sta_counter] = input[j_cp];
					input[j_cp] = -1;
					sta_counter++;
				}
			}
			if(large_num == check_head(station))
			{
				station[location(station,elements)] = -1;
				if(large_num-1!= check_head(station)
				&& exist(station,large_num-1,elements))
				// if paradox.
				{
					NIE_instructor = 1;
					break;
				}
			}
		}
		if(NIE_instructor == 0)
			printf("TAK\n");
		else
		{
			printf("NIE\n");
			NIE_instructor = 0;
		}
	}
return 0;
}
