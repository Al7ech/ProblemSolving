#include<stdio.h>

bool map[3100][6200];

void dfs(int x,int y,int size)
{
	if(size == 3)
	{
		map[x][y] = map[x+1][y-1] = map[x+1][y+1] = map[x+2][y-2] = map[x+2][y-1] = map[x+2][y] = map[x+2][y+1] = map[x+2][y+2] = 1;
		return;
	}
	dfs(x,y,size/2);
	dfs(x+size/2,y-size/2,size/2);
	dfs(x+size/2,y+size/2,size/2);
}


int main(void)
{
	int n;
	scanf("%d",&n);
	dfs(0,n-1,n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<2*n-1;j++)
		{
			if(map[i][j]) printf("*");
			else printf(" ");
		}
		puts("");
	}
	return 0;
}
