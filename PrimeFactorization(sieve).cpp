#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

void calculateLeastPrimeFactor(int arr[],int n)
{
	for (int i = 2; i*i <= n; ++i)
	{
		if(arr[i] == 0)
		{
			for (int j = i*i; j <= n; j+=i)
			{
				if(arr[j] == 0)
					arr[j] = i;
			}
		}
	}

	for (int i = 2; i < n; ++i)
	{
		if(arr[i] == 0)
			arr[i] = i;
	}
}

vector<int> factorize(int minPrimes[],int n)
{
	std::vector<int> res;
	while(n!=1)
	{
		res.push_back(minPrimes[n]);
		n /= minPrimes[n];
	}
	return res;	
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int *minPrimes = new int [n];
	std::vector<int> factors;
	calculateLeastPrimeFactor(minPrimes,n);
	int n1;
	scanf("%d", &n1);
	factors = factorize(minPrimes,n1);
	for (int i = 0; i < factors.size(); ++i)
	{
		printf("%d\n", factors[i]);
	}
	
	return 0;
}