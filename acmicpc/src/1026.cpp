#include <stdio.h>
#include <algorithm>
using namespace std;

int d[2][100];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<2;i++) for(int j=0;j<n;j++) scanf("%d",&d[i][j]);
	sort(d[0],d[0]+n);
	sort(d[1],d[1]+n);
	reverse(d[1],d[1]+n);
	int sum=0;
	for(int i=0;i<n;i++) sum+=d[0][i]*d[1][i];
	printf("%d",sum);
	return 0;
}
