#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unsigned long long N,k;
		scanf("%llu %llu",&N,&k);
		unsigned long long *arr = new unsigned long long [N];
		for (int i = 0; i < N; ++i)
		{
			scanf("%llu", &arr[i]);
		}
		unsigned long long min = arr[0];
		for (int i = 1; i < N; ++i)
		{
			if(arr[i] < min)
				min = arr[i];
		}
		unsigned long long time;
		if(min >= k)
			time = 0;
		else
			time = k - min;
		printf("%llu\n", time);
	} 
	return 0;
}