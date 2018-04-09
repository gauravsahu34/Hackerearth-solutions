#include <iostream>
#include <stdio.h>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int N;
		scanf("%d", &N);
		int arr[N][N];
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				scanf("%1d", &arr[i][j]);
			}
		}

		bool flag = true;
		int mid_n = N/2;
		for (int i = 0; i < mid_n; ++i)
		{
			for (int j = 0; j < mid_n; ++j)
			{
				if((arr[i][j] != arr[i][N-j-1]) || (arr[j][i] != arr[N-j-1][i]))
					flag = false;
			}
		}
		cout << flag << "\n";

		for (int i = 0; i < mid_n; ++i)
		{
			for (int j = N-1; j > mid_n; --j)
			{
				if((arr[i][j] != arr[N-i-1][j]) || (arr[j][i] != arr[j][N-i-1]))
					flag = false;
			}
		}

		cout << flag << "\n";

		if (flag)
			printf("YES\n");
		else
			printf("NO\n");

		/*for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}*/

	}
	return 0;
}