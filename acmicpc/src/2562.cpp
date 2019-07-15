#include <stdio.h>

int tmp,M=-1,idx;

int main(void)
{
    for(int i=0;i<9;i++)
    {
        scanf("%d",&tmp);
        if(tmp > M)
        {
            M = tmp;
            idx = i+1;
        }
    }

    printf("%d\n%d\n",M,idx);

    return 0;
}