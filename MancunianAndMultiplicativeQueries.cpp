#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define MOD 1000000007

typedef long long ll;

using namespace std;

int block_size;
struct Query
{
	int l,r,i;
}query[50001];
bool cmp(Query x, Query y)
{
	if(x.l/block_size != y.l/block_size)
		//differnt blocks, so sort by blocks.
		return x.l/block_size < y.l/block_size;
	//same block, so sort by r value
	return x.r < y.r;
}

int main(int argc, char const *argv[])
{
	int n,c,q;
	scanf("%d %d %d",&n,&c,&q);
	int a[50001];
	int cnt[c+1] = {0};
	int f[50002];
	block_size = sqrt(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i <= n; ++i)
	{
		scanf("%d",&f[i]);
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%d%d", &query[i].l, &query[i].r);
		query[i].l--; query[i].r--;
		query[i].i = i;
	}
	sort(query, query + q, cmp);
	int start = query[0].l;
	int end = start;
	cnt[a[start]]++;
	long long answer = 1;
	for (int i = 0; i < q; ++i)
	{
		long long result = 1;
		while(start < query[i].l)
		{
			cnt[a[start]]--;
			start++;
		}
		while(start > query[i].l)
		{
			start--;
			cnt[a[start]]++;
		}
		while(end < query[i].r)
		{
			end++;
			cnt[a[end]]++;
		}
		while(end > query[i].r)
		{
			cnt[a[end]]--;
			end--;
		}

		for(int j=1;j <= c;j++)
			result = (result * f[cnt[j]]) % MOD;
		answer = (answer * result) % MOD;
	}

	printf("%lld\n", answer);
	return 0;
}