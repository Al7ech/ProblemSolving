#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

char key[15];
char enc[105];
char text[105];

vector<pair<char, int>> V;

int main(void)
{
    scanf("%s\n", key);
    scanf("%s", enc);

    int blocklen = strlen(enc) / strlen(key);

    for (int i = 0; i < strlen(key); i++)
    {
        V.push_back(make_pair(key[i], i));
    }
    sort(V.begin(), V.end());

    for (int i = 0; i < strlen(key); i++)
    {
        for (int j = 0; j < blocklen; j++)
        {
            text[j * strlen(key) + V[i].second] = enc[i * blocklen + j];
        }
    }
    printf("%s", text);

    return 0;
}