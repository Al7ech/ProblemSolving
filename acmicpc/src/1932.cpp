#include<stdio.h>

int in[500][500];
int ans[500][500];

int max(int a,int b)
{
	if(a>b)
	return a;
	return b;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) for(int j=0;j<=i;j++) scanf("%d",&in[i][j]);
	for(int i=0;i<n;i++) ans[n-1][i] = in[n-1][i];
	for(int i=n-2;i>=0;i--)
	{
		for(int j=0;j<=i;j++)
		{
			ans[i][j] = max(ans[i+1][j] , ans[i+1][j+1])+in[i][j];
		}
	}
	printf("%d\n",ans[0][0]);
	return 0;
}
