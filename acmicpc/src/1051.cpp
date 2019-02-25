#include<stdio.h>

char map[50][50];

int min(int a,int b)
{
	if(a>b) return b;
	return a;
}

bool check(int a,int b,int c,int d)
{
	return ((map[a][b]==map[a][d])&&(map[c][b]==map[c][d])&&(map[a][b]==map[c][d]));
}

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	char tmp;
	for(int i=0;i<n;i++)
	{
		scanf("%s",map[i]);
		for(int j=0;j<m;j++) map[i][j] -='0';
	}
	int x = min(n,m)-1;
	for(;x>=0;x--)
	{
		for(int i=0;i<n-x;i++)
		{
			for(int j=0;j<m-x;j++)
			{
				if(check(i,j,i+x,j+x))
				{
					printf("%d\n",(x+1)*(x+1));
					return 0;
				}
			}
		}
	}
	return 0;
}
