#include <stdio.h>
#include <string.h>

int num[2][2000];
int answer[2000];
int len[2];
int cnt=0;

bool substractable(int x)
{
	if(x)
	{
		num[0][x]+=10*num[0][x-1];
		num[0][x-1]=0;
	}
	for(int i=0;i<len[1];i++)
	{
		if(num[0][x+i]>num[1][i])
			return true;
		if(num[0][x+i]<num[1][i])
			return false;
	}
	return true;
}

void substract(int x)
{
	for(int i=0;i<len[1];i++)
	{
		num[0][x+i]-=num[1][i];
		for(int j=0;num[0][x+i-j]<0;j++)
		{
			num[0][x+i-j]+=10;
			num[0][x+i-j-1]-=1;
		}
	}
	answer[cnt]++;
}

int main(void)
{
	char input[2000];
	for(int i=0;i<2;i++)
	{
		scanf("%s",input);
		len[i] = strlen(input);
		for(int j=0;input[j];j++) num[i][j] = input[j]-'0';
	}
	while(cnt+len[1]<=len[0])
	{
		if(substractable(cnt))
			substract(cnt);
		else
			cnt++;
	}
	cnt--;
	int idx;
	for(idx=0;answer[idx]==0&&idx<cnt;idx++);
	for(;idx<=cnt;idx++) printf("%d",answer[idx]);
	puts("");
	for(idx=0;num[0][idx]==0&&idx<len[0]-1;idx++);
	for(;idx<len[0];idx++) printf("%d",num[0][idx]);
	puts("");
}
