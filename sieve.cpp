#include <iostream>
#include <stdio.h>

using namespace std;

void sieveEratosthenes(bool isPrime[],long long n)
{
	for(long long i=0;i<=n;i++)
		isPrime[i] = true;  //Mark all the numbers as prime except 0 and 1
	isPrime[0] = false;
	isPrime[1] = false;
	for(long long i=2;i*i<=n;i++)  //Traverse over each prime numbers smaller than sqrt(N)
	{
		if(isPrime[i])
		{
			for(long long j=i*i;j<=n;j+=i)
				isPrime[j] = false;  //For each prime number, mark its multiples as composite numbers
		}							 //Numbers, which are not the multiples of any number, will remain marked as prime number and others will change to composite numbers.
	}

}

int main(int argc, char const *argv[])
{
	long long n;
	cin >> n;
	bool *isPrime = new bool [n+1];
	sieveEratosthenes(isPrime,n);
	int count = 0;
	for(long long i=1;i<=n;i++)
	{
		if(isPrime[i])
			count++;
	}
	printf("%d\n",count);

	return 0;
}