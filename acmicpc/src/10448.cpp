#include<stdio.h>

bool check[1001][4];

int main(void)
{
	int n;
	scanf("%d",&n);

	check[0][0]=1;

	for(int x=44;x>0;x--)
	{
		for(int i=x*(x+1)/2;i<=1000;i++)
		{
			for(int j=1;j<4;j++)
			{
				if(check[i-x*(x+1)/2][j-1]) check[i][j] = 1;
			}
		}
	}
	int idx;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&idx);
		if(check[idx][3]) puts("1");
		else puts("0");
	}
	return 0;
}
