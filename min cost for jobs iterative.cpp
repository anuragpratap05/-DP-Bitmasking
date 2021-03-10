# -DP-Bitmasking
#include<bits/stdc++.h>
using namespace std;

/*int mincost(int** cost, int i, int n, int mask)
{
	if (i >= n)
	{
		return 0;
	}
	int mini = INT_MAX;

	for (int j = 0; j < n; j++)
	{
		if (!(mask & (1 << j)))
		{
			int ans = cost[i][j] + mincost(cost, i + 1, n, mask | (1 << j));
			if (ans < mini)
			{
				mini = ans ;
			}
		}
	}

	return mini;
}*/
int mincost(int** cost, int n)
{
	int* dp = new int[1 << n];
	for (int i = 0; i < (1 << n); i++)
	{
		dp[i] = INT_MAX;
	}
	dp[0] = 0;

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
			if (!(mask & (1 << j)))
			{
				dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + cost[k][j]);
			}
		}
	}

	return dp[(1 << n) - 1];
}

int main()
{
#ifndef ONLINE_jUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;

	int** cost = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cost[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> cost[i][j];
		}
	}

	cout << mincost(cost,  n);


}
