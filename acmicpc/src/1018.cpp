#include <stdio.h>

char map[50][50];
int ans = 123456789;
int min(int a,int b)
{
	if(a>b) return b;
	return a;
}
int recolor(int a,int b)
{
	int cnt=0;
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			if(((i+j)%2==1 && map[a+i][b+j]=='W')||((i+j)%2==0 && map[a+i][b+j]=='B'))
				cnt++;
		}
	}
	return min(cnt,64-cnt);
}

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",map[i]);
	for(int i=0;i<n-7;i++)
	{
		for(int j=0;j<m-7;j++)
		{
			ans = min(ans,recolor(i,j));
		}
	}
	printf("%d",ans);
}
