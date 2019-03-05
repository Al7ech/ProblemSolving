#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int C;
string str;
int slen;
int D[11000];

int isDC(string str)
{
    int slen = str.size();
    int sub = str[1]-str[0];
    for(int i=1;i<slen-1;i++)
    {
        if(sub != str[i+1]-str[i])
            return -1;
    }
    return abs(sub);
}
int isBG(string str)
{
    int slen = str.size();
    for(int i=0;i<slen-2;i++)
        if(str[i] != str[i+2])
            return 0;
    
    return 1;
}

int value(string str)
{
    if(str == string(str.size(),str[0]))
        return 1;
    
    int dc = isDC(str);
    if(dc == 1) return 2;

    if(isBG(str))
        return 4;

    if(dc > 0)  return 5;
    return 10;
}

int pival(int idx)
{
    if(idx==slen)   return 0;
    if(idx>slen)    return 987654321;

    int &ret = D[idx];
    if(ret>0) return ret;

    ret = 987654321;

    for(int i=3;i<6;i++)
        ret = min(ret,value(str.substr(idx,i))+pival(idx+i));

    return ret;
}

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        memset(D,0,sizeof(D));
        cin >> str;
        slen = str.size();

        printf("%d\n",pival(0));
    }
    return 0;
}