#include<stdio.h>


int main(void)
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		char s[50];
		scanf("%s",s);
		int depth=0;
		for(int i=0;s[i];i++)
		{
			if(s[i]=='(') depth++;
			else depth--;
			if(depth<0) break;
		}
		if(!depth) puts("YES");
		else puts("NO");
	}
	return 0;
}
