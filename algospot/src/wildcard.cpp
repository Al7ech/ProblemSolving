#include <stdio.h>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

int C,N;
char W[150];
string F;
int D[150][150];

int main()
{
    scanf("%d",&C);
    for(int t=0;t<C;t++)
    {
        vector<string> ans;
        scanf("%s",W);
        scanf("%d",&N);
        for(int i=0;i<N;i++)
        {
            memset(D,0,sizeof(D));
            cin >> F;
            int Wlen = strlen(W),Flen = F.length();
            if(W[0] == '*') memset(D[0],1,sizeof(D[0]));
            else D[0][1] = (F[0] == '?' || F[0] == W[0]);
            for(int j=1;j<Wlen;j++)
            {
                for(int k=0;k<Flen+1;k++)
                {
                    if(W[j] == '*')
                    {
                        if(D[j-1][k])
                        {
                            memset(&D[j][k],1,4*(Flen-k+1));
                            break;
                        }
                    }
                    else
                    {
                        if(k==0)
                            continue;
                        if((W[j] == '?' || W[j] == F[k-1]))
                            D[j][k] = D[j-1][k-1];
                    }
                }
            }
            if(D[Wlen-1][Flen])
                ans.push_back(F);
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            cout << ans[i] << endl;
    }
    return 0;
}