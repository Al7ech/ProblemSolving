#include <stdio.h>

int l, r;
bool end;
bool dishonest;

int main(void)
{
    while (1)
    {
        dishonest = false;
        l = 1, r = 10;
        while (1)
        {
            int N;
            scanf("%d", &N);
            if (N == 0)
            {
                end = true;
                break;
            }

            char dec[2][10];
            scanf("%s %s", dec[0], dec[1]);
            if (dec[0][0] == 'r')
            {
                if (N < l || r < N)
                    dishonest = true;

                break;
            }
            else
            {
                if(dec[1][0] == 'h')
                    r = N-1;
                else if(dec[1][0] == 'l')
                    l = N+1;
                if(r<l)
                    dishonest = true;
            }   
        }
        if(end)
            break;
        if(dishonest)
            puts("Stan is dishonest");
        else
            puts("Stan may be honest");
    }

    return 0;
}