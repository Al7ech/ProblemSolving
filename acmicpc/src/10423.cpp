#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;

int N, K;

int idx[10001];
int ans = 0;

int main()
{
    scanf("%d\n%d", &N, &K);
    for (int i = 0; i < N; i++)
        scanf("%d", idx + i);

    sort(idx, idx + N);
    ans = idx[N - 1] - idx[0];

    for (int i = 1; i < N; i++)
        idx[i - 1] = idx[i] - idx[i - 1];

    sort(idx, idx + N - 1);
    reverse(idx, idx + N - 1);

    int loop = min(K - 1, N - 1);
    for (int i = 0; i < loop; i++)
        ans -= idx[i];

    printf("%d\n", ans);
    return 0;
}