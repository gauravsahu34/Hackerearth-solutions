#include <iostream>
#include <stdio.h>

##ifndef MOD
#define MOD 1000000007
#endif

int computeGCD(int a,int b)
{
	if( a==0 )
		return 1;
	return computeGCD(b,a%b)

}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int *arr = new int [N];
	for(int i = 0;i<N;i++)
		scanf("%d",arr[i]);
	int result = arr[0];
	unsigned long long product = arr[0];
	for(int i=1;i<N;i++)
	{
		if(arr[i] < result)
			result = computeGCD(result,arr[i]);
		else 
			result = computeGCD(arr[i],result);

		product = (product * arr[i]) % MOD;
	}

	return 0;
}