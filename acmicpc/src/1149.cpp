#include<stdio.h>

int d[1000][3],ans[1000][3];
int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<3;j++) {scanf("%d",&d[i][j]); ans[i][j] = 123456789;}
	for(int i=0;i<3;i++) ans[0][i] = d[0][i];
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(j==k) continue;
				ans[i][j] = min(ans[i][j],ans[i-1][k]+d[i][j]);
			}
		}
	}
	printf("%d",min(ans[n-1][0],min(ans[n-1][1],ans[n-1][2])));

	return 0;
}
