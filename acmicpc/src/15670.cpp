#include<stdio.h>

int val[100050];
int lev[100050];

int main(void)
{
	int n,m;
	scanf("%d %d", &n,&m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &val[i]);
		if(!i) continue;
		lev[i] += lev[i-1]+ (val[i-1]>val[i]);
	}
	while(m--)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		l--,r--;
		int ans = r-l+1-(lev[r]-lev[l]);
		if(l!=0) ans+=(val[l-1]>val[r])+lev[l-1]-lev[0];
		if(r!=n-1) ans+=(val[l]>val[r+1])+lev[n-1]-lev[r+1];
		printf("%d\n",ans);
	}
	return 0;
}
