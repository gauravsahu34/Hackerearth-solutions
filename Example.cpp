#include<iostream>
using namespace std;
typedef long long int lli;
int main()
{
    lli N;
    cin>>N;
 
    double dis[N],sum1=0.000000000,sum2=0.000000000;
    double str[N];
    for(int i=0;i<N;i++) cin>>dis[i];
    for(int i=0;i<N;i++) cin>>str[i];
    for(int j=0;j<N-1;j++)
    {
     for(double i=dis[j]+0.000000001;i<dis[j+1];i=i+0.000000001)
     {
          for(int k=0;k<N;k++)
          { if(dis[k]-i>0)
           {
            sum1=sum1+(str[k]/log2(2+dis[k]-i));
           }
           if(dis[k]-i<0)
           {
               sum2=sum2+(str[k]/log2(2+i-dis[k]));
           }
          }
          sum1 = sum1*pow(10, 10);
            sum1=trunc(sum1);
            sum2 = sum2*pow(10, 10);
            sum2=trunc(sum2);
          if(sum1==sum2)
          {
          cout<<i<<" ";
          }
          sum1=0;  sum2=0;
     }
    }
    return 0;
}