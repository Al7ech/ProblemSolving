#include<stdio.h>

int c[100001][100001];

int combination(int a,int b)
{
	if(b<a) return 0;
	if(a==0) return c[a][b] = 1;
	if(c[a][b]) return c[a][b];
	return c[a][b] = (combination(a-1,b-1) + combination(a,b-1));
}

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",combination(b,a));
	}
	return 0;
}
