#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<vector<int> > swt{ {0, 1, 2}, {3, 7, 9, 11}, {4, 10, 14, 15}, {0, 4, 5, 6, 7}, {6, 7, 8, 10, 12}, {0, 2, 14, 15}, {3, 14, 15}, {4, 5, 7, 14, 15}, {1, 2, 3, 4, 5}, {3, 4, 5, 9, 13}};

int C;

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        int state[16] = {0,};
        int known_ans = 1234567890;
        for(int i=0;i<16;i++)
        {
            int time;
            scanf("%d",&time);
            state[i] = (time/3)%4;
        }

        for(int i=0;i<(1<<20);i++)
        {
            int pressed = 0;
            for(int j=0;j<10;j++)
                pressed+=(i>>(2*j))%4;
            
            if(pressed >= known_ans)
                continue;
            
            int sum[16] = {0,};

            for(int j=0;j<10;j++)
                for(int k=0;k<swt[j].size();k++)
                    sum[swt[j][k]] = (sum[swt[j][k]]+(i>>(2*j))%4)%4;
            
            int check_ans = 0;

            for(int j=0;j<16;j++)
                check_ans += (state[j]+sum[j])%4;


            if(check_ans == 0)
                known_ans = pressed;
        }
        if(known_ans == 1234567890)
            puts("-1");
        else
            printf("%d\n",known_ans);
    }
    return 0;
}