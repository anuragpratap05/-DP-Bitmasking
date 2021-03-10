# -DP-Bitmasking
#include<bits/stdc++.h>
using namespace std;

int mincost(int like[][MAXN], int n)
{
	int* dp = new int[1 << n];
	for (int i = 0; i < (1 << n); i++)
	{
		dp[i] = 0;
	}
	dp[0] = 1;

	for (int mask = 0; mask < (1 << n) - 1; mask++)
	{
		int k = 0;
		int temp = mask;
		while (temp > 0)
		{
			if (temp % 2 == 1)
			{
				k++;
			}
			temp /= 2;
		}

		for (int j = 0; j < n; j++)
		{
			if (!(mask & (1 << j)) and like[k][j] == 1)
			{
				dp[mask | (1 << j)] += dp[mask];
			}
		}
	}

	return dp[(1 << n) - 1];
}
long long solve(int like[][MAXN],int N)
{
	return mincost(like,  N);
}
