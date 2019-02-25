#include <stdio.h>
#include <algorithm>
#define MAX 123456

int A[MAX];

int main(void)
{
    int N,M;

    scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d ",&A[i]);
    std::sort(A,A+N);

    scanf("%d",&M);
    int tmp;
    for(int i=0;i<M;i++)
    {
        scanf("%d",&tmp);
        if(tmp==*(std::lower_bound(A,A+N,tmp)))
            puts("1");
        else 
            puts("0");
    }

    return 0;
}