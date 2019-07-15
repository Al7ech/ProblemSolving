#include <stdio.h>

int main(void) {
    int a,b;
    scanf("%d%d",&a,&b);

    int tmp = b;
    for(int i=0;i<3;i++) {
        printf("%d\n",(tmp%10)*a);
        tmp/=10;
    }
    printf("%d\n",a*b);

    return 0;
}