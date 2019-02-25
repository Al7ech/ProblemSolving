#include<stdio.h>

int c[31][31];

int combination(int a,int b)
{
	if(b<a) return 0;
	if(a==0) return c[a][b] = 1;
	if(c[a][b]) return c[a][b];
	return c[a][b] = combination(a-1,b-1) + combination(a,b-1);
}

int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",combination(a,b));
	}
	return 0;
}
