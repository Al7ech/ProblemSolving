#include<stdio.h>
#include<vector>
using namespace std;

struct cord
{
	int x,y;
	cord(int xx,int yy) :
		x(xx),y(yy){}
};

cord dir[8] = {cord(1,1), cord(1,0), cord(1,-1), cord(0,-1), cord(-1,-1), cord(-1,0), cord(-1,1), cord(0,1)};

vector<cord> V;

char map[6][6];

int main(void)
{
	for(int i=0;i<6;i++) for(int j=0;j<6;j++) map[i][j] = '.';
	map[2][2] = map[3][3] = 'W';
	map[2][3] = map[3][2] = 'B';
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		a--,b--;
		V.push_back(cord(a,b));
	}
	for(int i=0;i<V.size();i++)
	{
		for(int j=0;j<8;j++)
		{

		}
	}
}
