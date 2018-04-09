#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[])
{
	int N,t;
	scanf("%d %d",&t,&N);
	int *arr = new int [N+1];
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j*j<=i;j++)
		{
			int d1,d2;
			if(i%j==0)
			{
				d1 = j;
				d2 = i / d1;
				if(d1 != d2)
					arr[i] = arr[i] + 2;
				else
					arr[i] = arr[i] + 1;
			}

		}	
	}
	int *arr1 = new int [N+1];
	for(int i=0;i<=N;i++)
		arr1[i] = arr[i];

		
	while(t--)
	{
		int k;
		scanf("%d",&k);
		int min = arr1[k];
		sort(arr,arr+N+1);
		int count = 0;
		for(int i=1;i<N;i++)
		{
			if(arr[i]<min)
				count++;
			else
				break;
		}
		printf("%d\n", count);

	}
	return 0;
}