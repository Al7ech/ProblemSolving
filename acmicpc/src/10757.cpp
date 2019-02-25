#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;

char num[3][20000];

int main(void)
{
	scanf("%s %s",num[0],num[1]);

	reverse(num[0],num[0]+strlen(num[0]));
	fill(num[0]+strlen(num[0])-1,num[0]+20000,'0');
	reverse(num[1],num[1]+strlen(num[1]));
	fill(num[1]+strlen(num[1]),num[1]+20000,'0');
	for(int i=0;i<20000;i++)
	{
		num[0][i] = num[0][i]-'0'+num[1][i]-'0';
		if(num[0][i]>10)
		{
			num[0][i]-=10;
			num[0][i+1]++;
		}
	}
	reverse(num[0],num[0]+strlen(num[0]));
	int len = strlen(num[0]);
	printf("len : %d\n",len);
	int i=0;
	for(;num[0][i]=='0';i++);
	for(;i<len;i++) printf("%d",num[0][i]);
	puts("");
	return 0;
}
