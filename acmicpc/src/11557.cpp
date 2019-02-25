#include<stdio.h>
#include<algorithm>
using namespace std;

struct alch
{
	char name[25];
	int val;
};

bool cmp(alch a, alch b)
{
	return a.val<b.val;
}

alch al[100];


int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%s %d",al[i].name,&al[i].val);
		sort(al,al+n,cmp);
		reverse(al,al+n);
		printf("%s\n",al[0].name);
	}
	return 0;
}
