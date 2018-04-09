#include <stdio.h>
#include <iostream>
#include <string>
#define MOD 1000000007
using namespace std;
typedef unsigned long long ull;
ull modExponentiation(ull base, ull power)
{
    ull result = 1;
    while(power>0)
    {
        if(power % 2 == 1)
            result = (result * base) % MOD;
        base = (base*base) % MOD;
        power = power / 2;
    }
    return result;

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int mod1;
        string s1,s2;
        scanf("%s%s",&s1,&s2);
        ull base, power;
        ull base_length, power_length;
        base_length = s1.length();
        power_length = s2.length();
        for(ull i=0;i<base_length;i++)
            base = ((base*10) + (s1[i] - '0')) % MOD;
        for(ull i=0;i<power_length;i++)
            power = ((power*10) + (s2[i] - '0')) % MOD;
        printf("%llu",modExponentiation(base,power));

    }
}
