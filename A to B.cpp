#include <iostream>
#include <stdio.h>
#include <vector> 
using namespace std;

typedef unsigned long long ll;
void constructB(ll arr_A[], ll arr_B[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr_B[i] = 1;
		for (int j = 0; j < n; ++j)
		{
			if(i!=j)
				arr_B[i] = arr_B[i] *arr_A[j];
		}
	}
}

/*void printB(ll arr_B[])
{
	for (int i = 0; i < N; ++i)
	{
		printf("%llu\n", arr_B[i]);
	}
}*/
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d", &N);
	ll *arr_A = new ll [N];
	for (int i = 0; i < N; ++i)
		scanf("%llu",&arr_A[i]);
	ll *arr_B = new ll [N];
	int Q;
	scanf("%d", &Q);
	while(Q--)
	{
		ll input;
		std::vector<ll> v;
		cin >> input;
		v.push_back(input);
		if(v[0] == 1)
		{
			int p = v[1] - 1;
			constructB(arr_A,arr_B,N);
			printf("%llu\n", arr_B[p]);
		}
		else
		{
			int p = v[1] - 1;
			arr_A[p] = v[2];

		}

	}
	
	
	return 0;
}