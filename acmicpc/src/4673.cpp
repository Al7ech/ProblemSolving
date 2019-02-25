#include <stdio.h>

bool chk[10001];

int main(void)
{
	for(int i=1;i<10001;i++){
		int n=i;
		int sum=i;
		while(n)
		{
			sum+=n%10;
			n/=10;
		}
		if(sum<10001) chk[sum]=1;
	}
	for(int i=1;i<10001;i++){
		if(!chk[i]) printf("%d\n",i);
	}

	return 0;
}
