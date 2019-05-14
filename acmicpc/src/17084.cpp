#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;
typedef long long ll;
// 0. 크기가 1이면 전처리
// 1. 맨 앞에 오는 피보나치가 몇번째인지 구하기
// 2. 배열이 맞는지 확인하기
// 3. 답 세기

ll f[1000]; // f[93] = 0
ll matrix[1005][1005];
int first_idx;
bool check_matrix = true;
ll ans;
ll N, P;

ll fib(int ith)
{
    if (ith <= 0)
        return -1;
    if (f[ith] != 0)
        return f[ith];

    else
        return f[ith] = fib(ith - 1) + fib(ith - 2);
}

int main(void)
{
    f[1] = -7540113804746346429;
    f[2] = 4660046610375530309;

    scanf("%lld %lld", &N, &P);

    for (int i = 0; i < P; i++)
        for (int j = 0; j < P; j++)
            scanf("%lld", &matrix[i][j]);

    // 0
    if (P == 1)
    {
        if (matrix[0][0] == 1)
        {
            if (N == 1)
                ans = 1;
            else
                ans = N * 3 - 3;
        }
        else
        {
            vector<int> idx;
            for (int i = 1; i < 186; i++)
            {
                if (fib(i) == matrix[0][0])
                {
                    idx.push_back(i);
                }
            }
            for (int index : idx)
            {
                if (index <= 93)
                    ans += max((ll)0, -94 + N + index);
                else
                    ans += max((ll)0, 94 - index + N);
            }
        }
        printf("%lld\n", ans);
        return 0;
    }

    // 1
    first_idx = -1;
    for (int i = 1; i < 186; i++)
    {
        if (fib(i) == matrix[0][0] && fib(i + 1) == matrix[0][1])
        {
            first_idx = i;
            break;
        }
    }
    // 2
    if (first_idx == -1)
        check_matrix = false;
    for (int i = 0; i < P; i++)
    {
        for (int j = 0; j < P; j++)
        {
            if (matrix[i][j] != fib(first_idx - i + j))
            {
                check_matrix = false;
                break;
            }
        }
    }
    if (!check_matrix)
    {
        puts("0");
        return 0;
    }

    if (first_idx <= 93)
        ans = max((ll)0, first_idx - 94 + N - P + 1);
    else
        ans = max((ll)0, 94 - first_idx + N - P + 1);

    printf("%lld\n", ans);

    return 0;
}