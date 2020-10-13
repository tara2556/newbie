#include <pch.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <cstdlib>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
int dp[1005][1005];
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		int d = a.length();
		int e = b.length();
		for (int i = 0; i < 1005; i++)
			memset(dp[i], 0, sizeof(dp[i]));
		for (int i = 1; i <= d; i++)
			for (int j = 1; j <= e; j++)
			{
				if (a[i - 1] == b[j - 1])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		cout << dp[d][e] << '\n';
	}
}
