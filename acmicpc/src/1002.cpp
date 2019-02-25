#include <stdio.h>

int t;

struct dot
{
	int x,y,r;
	bool operator ==(dot& other)
    {
        return (this->x == other.x && this->y == other.y && this->r == other.r);
    }
};

void input(dot &name)
{
	scanf("%d %d %d",&name.x,&name.y,&name.r);
}
int pow(int a,int b)
{
	int ret=a;
	while(--b)
	{
		ret*=a;
	}
	return ret;
}
int distance(dot a,dot b)
{
	return pow(a.x-b.x,2) + pow(a.y-b.y,2);
}

int main(void)
{
	scanf("%d",&t);
	for (int i = 0; i < t; i++)
	{
		dot jo,baek;
		input(jo);
		input(baek);
		if(jo == baek)
		{
			puts("-1");
			continue;
		}
		int dist = distance(jo,baek);
		if (dist > pow(jo.r+baek.r,2) || dist < pow(jo.r-baek.r,2))
			puts("0");
		else if (dist < pow(jo.r+baek.r,2) && dist > pow(jo.r-baek.r,2))
			puts("2");
		else
			puts("1");
	}
	return 0;
}
