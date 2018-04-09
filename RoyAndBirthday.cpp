#include <iostream>
#include <stdio.h>
#include <string>

#define MOD 1000000007

using namespace std;

unsigned long long computeFactorial(unsigned long long l)
{
	unsigned long long result = 1;
	if(l == 0)
		return 1;
	while(l>0)
	{
		result = (result * l) % MOD;
		l--;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		string str;
		cin >> str;

		unsigned long long len = str.length();
		cout << len;
		unsigned long long total = computeFactorial(len);
		unsigned long long a[5] = {0,0,0,0,0};
		for(int i=0;i<len;i++)
		{
			if(str[i] == 'a')
				a[0] = a[0] + 1;
			else if(str[i] == 'e')
				a[1] = a[1] + 1;
			else if(str[i] == 'i')
				a[2] = a[2] + 1;
			else if(str[i] == 'o')
				a[3] = a[3] + 1;
			else if(str[i] == 'u')
				a[4] = a[4] + 1;
		}

		unsigned long long sum = 0;
		for(int i=0;i<5;i++)
			sum = sum + a[i];
		unsigned long long consonant = len - sum + 1;
		consonant = computeFactorial(consonant);
		unsigned long long sum1;
		sum1 = computeFactorial(sum);
		unsigned long long sum2 = 1;
		for(int i=0;i<5;i++)
			sum2 = (sum2 * computeFactorial(a[i])) % MOD;
		sum1 = (sum1 * consonant) % MOD;
		unsigned long long ans = sum1 / sum2;
		total = total / sum2;
		ans = total - ans;
		if(ans <= 0)
			printf("-1\n");
		else
			printf("%lld\n",ans);

	}

	return 0;
}