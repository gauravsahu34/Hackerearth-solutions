#include <iostream>
#include <stdio.h>


#define MOD 1000000007

using namespace std;
int computeGCD(int a,int b)
{
	if( b==0 )
		return a;
	return computeGCD(b,a%b);

}//15844 
unsigned long long computeExponent(unsigned long long c,int d)
{
	unsigned long long exp = 1;
    while(d>0)
    {
        if(d % 2 == 1)
            exp = (exp * c) % MOD;
        c = (c*c) % MOD;
        d = d/2;
    }
    return exp;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int *arr = new int [N];
	for(int i = 0;i<N;i++)
		scanf("%d",&arr[i]);
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

	//std:cout << result << " " << product;

	cout << computeExponent(product,result) << "\n";
	return 0;
}