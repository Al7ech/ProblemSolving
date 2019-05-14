#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int pop_count = 0;
int pop_idx;
int smooth_count = 0;

int a[100005];

int ans = 0;

int N;

int main()
{
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 1; i < N; i++)
    {
        if (a[i - 1] > a[i])
        {
            pop_count++;
            pop_idx = i;
        }
        if (a[i - 1] == a[i])
            smooth_count++;
    }
    if (pop_count > 1)
        ans = 0;
    else if (pop_count == 1)
    {
        if (pop_idx == 1 || a[pop_idx - 2] <= a[pop_idx]) // delete a[idx-1]
            ans++;
        if (pop_idx == N - 1 || a[pop_idx - 1] <= a[pop_idx + 1])
            ans++;
    }
    else
        ans = N;

    printf("%d\n", ans);

    return 0;
}