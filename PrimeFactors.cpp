#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
//this is used to compute prime factors of a number
//this algorithm is of O(sqrt(N)) complexity

vector<int> calculatePrimeFactors(int n)
{
	std::vector<int> v;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0) // traverse until all the multiple of the prime i has been cancelled
		{
			v.push_back(i);
			n /= i;
		}
	}
	if(n!=1)     //if we have left with n != 1 then surely it is the last prime number 
		v.push_back(n);// for example 290
	return v;
}
int main()
{
	std::vector<int> v_primes;
	int n;
	cin >> n;
	v_primes = calculatePrimeFactors(n);
	for(int i=0;i<v_primes.size();i++)
		printf("%d\n", v_primes[i]);
}