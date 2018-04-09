#include <iostream>
#include <stdio.h>
#define MOD 1000000007

using namespace std;

int calculateGCD(int a,int b)
{

    if(b==0)
        return a;
    else
        return calculateGCD(b,a%b);

}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int *num = new int [n];
		int *den = new int [n];
		int num_t = 1;
		int den_t = 1;
		for(int i=0;i<n;i++)
		{
			scanf("%d %d",&num[i],&den[i]);
			num_t = (num_t * num[i]) % MOD;
			den_t = (den_t * den[i]) % MOD;
		}	
		//cout << num_t << " " << den_t << endl;
		int gcd = calculateGCD(num_t,den_t);
		//cout << gcd << endl;
		num_t = num_t / gcd;
		den_t = den_t / gcd;

		printf("%d %d\n",num_t,den_t);

	}
	return 0;
}