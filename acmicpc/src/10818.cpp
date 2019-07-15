#include <stdio.h>

int a;
int m,M;
int tmp;

int main(void)
{
    m = 1e+9;
    M = -m;
    scanf("%d",&a);
    for(int i=0;i<a;i++) {
        scanf("%d",&tmp);
        if(tmp > M) M = tmp;
        if(tmp < m) m = tmp;
    }

    printf("%d %d\n",m,M);

    return 0;
}