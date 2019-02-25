#include <stdio.h>
#include <string.h>

char s[2][200];

bool check()
{
	int len = strlen(s[0]);
	for(int i=0;i<len;i++)
	{
		if(s[0][i] != s[1][i])
			return false;
	}
	return true;
}

int main(void)
{
	scanf("%s",s[0]);
	int len = strlen(s[0]);
	for(int i=0;i<len;i++) s[1][i] = s[0][len-1-i];
	printf("%d",check());
	return 0;
}
