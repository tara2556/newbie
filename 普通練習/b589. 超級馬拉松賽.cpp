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
#include <iomanip>
#define ll long long
#define pi pair<int,int>
#define mk make_pair
using namespace std;
ll dp[100][4];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	while (cin >> n && n)
	{
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			cin >> dp[i][0];
		dp[0][1] = 0;
		dp[0][2] = dp[0][0];
		dp[0][3] = dp[0][0] * 2;
		for (int i = 1; i < n; i++)
		{
			dp[i][1] = max(dp[i-1][1],max( dp[i-1][2], dp[i-1][3]));
			dp[i][2] = max(dp[i-1][1], dp[i-1][2]) + dp[i][0];
			dp[i][3] = max(dp[i - 1][1], dp[i - 1][2]) + dp[i][0] * 2;
		}
		cout << max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3])) << '\n';
	}
}
