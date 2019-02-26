#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>

using namespace std;

bool isGroupWord(int check[26])
{
    for(int i=0;i<26;i++)
        if(check[i]>1)
            return false;
    
    return true;
}

int main()
{
    int N;
    int cnt=0;
    scanf("%d",&N);

    for(int i=0;i<N;i++)
    {
        char str[150];
        int check[26] = {0,};

        scanf("%s",str);

        int len = strlen(str);

        check[str[0]-'a']++;
        for(int j=1;j<len;j++)
            check[str[j]-'a'] += str[j]!=str[j-1];

        
        cnt+=isGroupWord(check);
    }

    printf("%d\n",cnt);

    
    return 0;
}