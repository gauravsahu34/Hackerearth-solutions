#include <iostream>
#include <stdio.h>
#include <vector>t
typedef long long ll;

using namespace std;

ll computeGCD(ll a,ll b)
{
	if(b == 0)
		return a;
	else
		return computeGCD(b,a%b);
}

unsigned long long computeLCM(ll arr[], ll n)
{
	unsigned long long res = arr[0];
	for (ll i = 1; i < n; ++i)
	{
		res = (res * arr[i]) / (computeGCD(res,arr[i])); 
	}
	return res;
}

ll main(ll argc, char const *argv[])
{
	ll t;
	scanf("%d", &t);
	while(t--)
	{
		ll n;
		scanf("%d", &n);
		ll *target = new ll [n];
		for(ll i=0;i<n;i++)
			scanf("%d", &target[i]);
		unsigned long long ans = computeLCM(target,n);
		cout << ans << "\n";
	}

	
	return 0;
}