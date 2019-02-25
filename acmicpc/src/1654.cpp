#include<stdio.h>

int len[10000];
long long sum;

int main(void)
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&len[i]);
		sum+=(long long)len[i];
	}
	sum/=(long long)k;
	long long min=0,max=sum*2;
	long long count, mid;

	while(min+1<max){
		count=0;
		mid = (min+max)/2;

		//printf("%lld %lld %lld\n",min,mid,max);
		for(int i=0;i<n;i++){
			count+=(long long)len[i]/mid;
		}
		if ((int)count<k)
			max=mid;
		else
			min=mid;
	}

	printf("%lld\n",min);



	return 0;
}
