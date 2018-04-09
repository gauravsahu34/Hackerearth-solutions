#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

const int MAX = 10000001;
bool prime[MAX+1];
std::vector<int> v;
void sieve()
{
	prime[0] = false;
	prime[1] = false;
	for (int i = 2; i*i <= MAX; ++i)
	{
		if(prime[i] == true)
		{
			for (int j = i*i; j <= MAX; j+=i)
			{
				prime[j] = false;
			}
		}
	}

	for (int i = 2; i <= MAX; ++i)
	{
		if(prime[i])
		{
			v.push_back(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	sieve();
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n == 1)
			printf("2\n");
		else if(prime[n])
		{
			printf("n\n");
		}
		else
		{
			//std::vector<int> :: iterator n_prime1;
			int low, high;
			low = *(lower_bound(v.begin(),v.end(),n));
			high = *(lower_bound(v.begin(), v.end(),n)-1);
			cout << low << " " << high;
			if(abs(low - n) <= abs(high - n))
				printf("%d\n", low);
			else
				printf("%d\n", high);

		}
	}
	return 0;
}