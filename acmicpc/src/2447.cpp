#include<stdio.h>

bool map[2500][2500];

void dfs(int x,int y,int size)
{
	if(size==1)
	{
		map[x][y]=1;
		return;
	}
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(i!=1||j!=1) dfs(x+i*size/3,y+j*size/3,size/3);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	dfs(0,0,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j]) printf("*");
			else printf(" ");
		}
		puts("");
	}
	return 0;
}
