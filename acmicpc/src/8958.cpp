#include <stdio.h>
#include <string.h>

int n, sum, add;
char s[100];

int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        int len = strlen(s);
        sum = 0;
        add = 1;
        for(int j=0;j<len;j++)
        {
            if(s[j] == 'O')
                sum+=add++;
            else
                add = 1;
        }
        printf("%d\n",sum);
    }


    return 0;
}