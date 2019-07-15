#include <stdio.h>

int main(void) {
    int a,b;
    scanf("%d%d",&a,&b);

    b+=15;
    if(b>59)
    {
        b%=60;
        a++;
    }
    a--;
    if(a>23 || a<0) a = (a+24)%24;
    
    printf("%d %d\n",a,b);

    return 0;
}