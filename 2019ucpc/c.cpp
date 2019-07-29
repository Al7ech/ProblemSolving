#include <stdio.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> SE;
vector<pair<int, int>> ES;

int N, K;

int main(void)
{
    scanf("%d%d", &N, &K);

    for (int i = 0; i < N; i++)
    {
        int s, e;
        scanf("%d %d", &s, &e);
        ES.push_back(make_pair(e, s));
        SE.push_back(make_pair(s, e));
    }
    sort(SE.begin(), SE.end());
    sort(ES.begin(), ES.end());

    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j <)
    }

    return 0;
}