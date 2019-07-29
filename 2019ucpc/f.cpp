#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
double D[2000][6][6][6];

int getMoney(int a, int b, int c)
{
    if (a == b && b == c)
        return 10000 + 1000 * a;
    if (a == b)
        return 1000 + 100 * a;
    if (b == c)
        return 1000 + 100 * b;
    if (c == a)
        return 1000 + 100 * c;

    return 100 * max(a, max(b, c));
}

double dfs(int depth, int a, int b, int c)
{
    if (N == depth)
        return D[depth][a][b][c] = getMoney(a, b, c);

    if (D[depth][a][b][c] != 0)
        return D[depth][a][b][c];

    double ret = 0;
    for (int i = 1; i <= 6; i++)
        ret += dfs(depth + 1, b, c, i);
    return D[depth][a][b][c] = max((double)getMoney(a, b, c), ret / 6);
}

int main(void)
{
    scanf("%d", &N);

    double ans = 0;

    for (int i = 0; i < 216; i++)
    {
        ans += dfs(3, i / 36 + 1, i / 6 % 6 + 1, i % 6 + 1);
    }
    printf("%lf\n", ans / 216);

    return 0;
}