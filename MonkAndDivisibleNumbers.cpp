#include <iostream>
#include <stdio.h>

#define MOD 1000000007
typedef unsigned long long ll;

ll ModularExponentiation(ll b, ll c)
{
	ll result = 1;
	while(c > 0)
	{
		if(c % 2 == 1)
			result = (result * b) % MOD;
		b = (b * b) % MOD;
		c = c/2;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c;
		scanf("%d%d%d",&a,&b,&c);

	}
	return 0;
}