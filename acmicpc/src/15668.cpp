#include<stdio.h>
#include<vector>
using namespace std;

vector<int> V;

int main(void)
{
	for(int N=1;N<=100000;N++)
	{
		bool clear = 0;
		for(int i=1;i<(N+1)/2;i++)
		{
			bool check[10]={0,};
			bool flag=0;
			int a = i;
			int b = N-i;
			while(a)
			{
				if(check[a%10])
				{
					flag=1;
					break;
				}
				check[a%10]=1;
				a/=10;
			}
			if(flag) continue;
			while(b)
			{
				if(check[b%10])
				{
					flag=1;
					break;
				}
				check[b%10]=1;
				b/=10;
			}
			if(!flag)
			{
				clear = 1;
				printf("clear : %d %d\n",N,i);
				break;
			}
		}
		if(!clear)
		{
			V.push_back(N);
			//break;
		}
	}
	for(int i=0;i<V.size();i++)	printf("%d\n", V[i]);
	return 0;
}
