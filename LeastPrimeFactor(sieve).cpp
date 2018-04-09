#include <iostream>
#include <stdio.h>

using namespace std;
// Time Complexity = O(Nlog N)
//Auxiliary Space = O(N)
//This algorithm is used to compute least prime factor of numbers 1 to N
//This is derived from sieve Erastothenes
 
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

int main()
{
	int n;
	scanf("%d", &n);
	int *arr = new int [n];
	calculateLeastPrimeFactor(arr,n);
	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", arr[i]);
	}
}