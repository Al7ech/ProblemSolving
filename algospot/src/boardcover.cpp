#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int C;
int H,W;
char map[30][30];

int rec_ans(int h,int w)
{
    int ret = 0;

    while(map[h][w]=='#')
    {
        h+=(w+1)/W;
        w =(w+1)%W;
    }

    if(h>=H)
        return 1;

    if(map[h][w] == '.' && map[h][w+1] == '.' && map[h+1][w] == '.' && w+1<W && h+1<H)
    {
        map[h][w] = map[h][w+1] = map[h+1][w] = '#';
        ret += rec_ans(h,w);
        map[h][w] = map[h][w+1] = map[h+1][w] = '.';
    }
    if(map[h][w] == '.' && map[h][w+1] == '.' && map[h+1][w+1] == '.' && w+1<W && h+1<H)
    {
        map[h][w] = map[h][w+1] = map[h+1][w+1] = '#';
        ret += rec_ans(h,w);
        map[h][w] = map[h][w+1] = map[h+1][w+1] = '.';
    }
    if(map[h][w] == '.' && map[h+1][w] == '.' && map[h+1][w+1] == '.' && w+1<W && h+1<H)
    {
        map[h][w] = map[h+1][w] = map[h+1][w+1] = '#';
        ret += rec_ans(h,w);
        map[h][w] = map[h+1][w] = map[h+1][w+1] = '.';
    }
    if(w!=0 && map[h][w] == '.' && map[h+1][w] == '.' && map[h+1][w-1] == '.' && h+1<H)
    {
        map[h][w] = map[h+1][w] = map[h+1][w-1] = '#';
        ret += rec_ans(h,w);
        map[h][w] = map[h+1][w] = map[h+1][w-1] = '.';
    }


    return ret;
}


int main()
{
    scanf("%d",&C);

    for(int t=0;t<C;t++)
    {
        scanf("%d %d\n",&H,&W);

        int cnt=0;

        for(int i=0;i<H;i++)
        {
            scanf("%s",map+i);
            for(int j=0;j<W;j++) cnt+=map[i][j]=='.';
        }

        if(cnt%3)
        {
            puts("0");
            continue;
        }
        
        printf("%d\n",rec_ans(0,0));

    }

    return 0;
}