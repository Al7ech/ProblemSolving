#include<stdio.h>

long long d[40][400];

int main(void)
{
	d[1][0] = d[1][1] = 1;
	for(int i=2;i<=20;i++) for(int j=0;j<i+1;j++) for(int k=0;k<i*(i+1)/2;k++) d[i][j+k] += d[i-1][k];
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b;
		scanf("%d %d",&a,&b);

		printf("%lld\n",d[a][b]);
	}

	return 0;
}
