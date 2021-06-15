#include <stdio.h>

int main()
{
    int prime[25] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int first,second,flag = 0;
    scanf("%d%d",&first,&second);
    for(int i=first;i<=second;++i)
    {
        for(int j=0;j<25;++j)
        {
            if(i == prime[j])
            {
                flag = 1;
                printf("%d ",prime[j]);
            }
        }
    }
    if(!flag)
        printf("NO");
    return 0;
}

