#include <stdio.h>

int l, r;
bool end, honest;

int main(void)
{
    while (1)
    {
        char a[10], b[10];
        int val;

        while (1)
        {
            scanf("%d", &val);
            if (val == 0)
            {
                end = true;
                break;
            }
            honest = true;

            scanf("%s %s", a, b);
            if (b[0] == 'h')
            {
                if (val <= l)
                {
                    honest = false;
                    break;
                }
                r = val - 1;
            }
            else if (b[0] == 'l')
            {
                if (r <= val)
                {
                    honest = false;
                    break;
                }
                l = val + 1;
            }
            else
                break;
        }
        if (end)
            break;
        while (b[0] != 'o')
        {
            scanf("%d\n", &val);
            scanf("%s %s", a, b);
        }
        if (honest)
            puts("Stan may be honest");
        else
            puts("Stan is dishonest");
    }
    return 0;
}