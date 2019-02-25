#include <stdio.h>
#include <string.h>

char s[100];
int cnt;

int solution(int i)
{
	if(s[i]=='c' ||s[i]=='s' ||s[i]=='z')
	{
		if(s[i+1]=='=')
		{
			cnt++;
			return 1;
		}
	}
	if(s[i] == 'd')
	{
		if((s[i+1]=='z' && s[i+2] =='='))
		{
			cnt++;
			return 2;
		}

	}
	if(s[i] == 'c' || s[i] =='d')
	{
		if(s[i+1] == '-')
		{
			cnt++;
			return 1;
		}
	}
	if(s[i] == 'l' || s[i] =='n')
	{
		if(s[i+1] == 'j')
		{
			cnt++;
			return 1;
		}
	}
	cnt++;
	return 0;

}

int main(void)
{
	scanf("%s",s);
	for(int i=0;i<strlen(s);i++)
	{
		i+=solution(i);
	}
	printf("%d",cnt);
}
