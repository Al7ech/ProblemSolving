#include<stdio.h>

char map[12][6];

int counter(int x,int y)
{

}
void destroy(int x,int y)
{

}

bool puyoable()
{
	bool able = 0;
	for(int i=0;i<12;i++)
	{
		for(int j=0;j<6;j++)
		{
			if(map[i][j] != '.' && counter(i,j)>=4)
			{
				destroy(i,j);
				able = 1;
			}
		}
	}
	if (able)
	{
		for(int j=0;j<6;j++)
		{
			for(int i=10;i>=0;i--)
			{
				if(map[i][j]!='.')
				{
					for(int k=i;k!=11&&map[k+1][j]!='.';k++)
					{
						map[k][j] = map[i][j];
						map[i][j] = '.'
					}
				}
			}
		}
	}
	return able;
}

int main(void)
{
	for(int i=0;i<12;i++) scanf("%s",map[i]);
	int cnt=0;
	for(;puyoable();cnt++);
	return 0;
}
