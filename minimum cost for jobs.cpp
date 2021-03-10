#include<bits/stdc++.h>
using namespace std;

int mincost(int** cost, int i, int n, int mask)
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

	cout << mincost(cost, 0, n, 0);


}
