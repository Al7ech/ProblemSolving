#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define INF 987654321

struct edge
{
	int U,V;
	edge(int u, int v)
        : U(u), V(v){}
};

vector<edge> E;
int idx[100050];
int ans[100050];
bool visit[100050];

bool cmp(edge a,edge b)
{
	return a.U<b.U;
}
int BFS(int x)
{
	int sum=0;
	visit[x]=1;
	for(int i=idx[x];i<idx[x+1];i++)
		if(!visit[E[i].V])
			sum+=BFS(E[i].V);
	return ans[x]=1+sum;
}



int main(void)
{
	int N,R,Q;
	scanf("%d %d %d",&N,&R,&Q);
	R--;
	for(int i=0;i<N-1;i++)
	{
		int U,V;
		scanf("%d %d",&U,&V);
		U--,V--;
		E.push_back(edge(U,V));
		E.push_back(edge(V,U));
	}
	sort(E.begin(),E.end(),cmp);
	for(int i=0;i<N;i++) idx[i]=INF;
	int len = E.size();
	for(int i=0;i<len;i++) idx[E[i].U] = min(i,idx[E[i].U]);
	idx[N]=len;
	int tmp = BFS(R);
	for(int i=0;i<Q;i++)
	{
		int U;
		scanf("%d",&U);
		printf("%d\n",ans[U-1]);
	}
}
