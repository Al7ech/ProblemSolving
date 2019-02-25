#define INF 987654321

#include <stdio.h>

int map[250][250];

int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) map[i][j] = INF;
	for(int i=0;i<m;i++)
	{
		int a,b,state;
		scanf("%d %d %d",&a,&b,&state);
		a--,b--;
		if(state)
			map[a][b] = map[b][a] = 0;
		else
		{
			map[a][b] = 0;
			map[b][a] = 1;
		}
	}
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(map[i][k]+map[k][j]<map[i][j])
					map[i][j] = map[i][k]+map[k][j];
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",map[a-1][b-1]);
	}
	return 0;
}
