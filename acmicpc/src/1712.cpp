#include <stdio.h>

int a,b,c;


int main(void)
{
    scanf("%d%d%d",&a,&b,&c);
    
    if(b>=c)
        puts("-1");
    else
        printf("%d\n",a/(c-b) + 1);


    return 0;
}