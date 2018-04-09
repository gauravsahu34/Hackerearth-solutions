#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int n,q;
	scanf("%d%d",&n,&q);
	int *city = new int [n];
	int arr[200001] = {0};
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&city[i]);
		arr[city[i]] = i;
	}
	while(q--)
	{
		int y,z;
		char d;
		scanf("%d %d %c",&y,&z,&d);
		memset(arr,-1,200001*sizeof(int));
		int index = arr[z];
		int count = -1;
		if(index == -1)
			printf("-1\n");
		else if(d == 'L')
		{
			for(int i=y;;i=(i-1+n)%n)
			{
				count++;
				if(i == index)
					break;
			}
			printf("%d\n", count);
		}
		else if(d == 'R')
		{
			for (int i = y;;i=(i+1)%n)
			{
				count++;
				if(i == index)
					break;
			}
			printf("%d\n", count);
		}


	} 
	return 0;
}