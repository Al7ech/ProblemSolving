#include<stdio.h>
#include<string.h>

int cnt=0;
bool check=0;
char tmp[1000000];

int main(void)
{
    gets(tmp);
    tmp[strlen(tmp)]= ' ';
    int len = strlen(tmp);
    for(int i=0;i<len;i++)
    {
        if(check && tmp[i] == ' ')
        {
            cnt++;
            check=0;
        }
        if(!check && tmp[i] != ' ')
        {
            check=1;
        }
    }

    printf("%d",cnt);
    return 0;
}
